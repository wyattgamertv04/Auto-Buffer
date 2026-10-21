#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/binding/GameObject.hpp>

using namespace geode::prelude;

class $modify(BuffedPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontSave) {
        // Run standard PlayLayer initialization first
        if (!PlayLayer::init(level, useReplay, dontSave)) {
            return false;
        }

        // Check if master toggle is enabled
        bool modEnabled = Mod::get()->getSettingValue<bool>("enable-mod");
        if (!modEnabled) {
            return true;
        }

        bool scaleHazards = Mod::get()->getSettingValue<bool>("scale-hazards");
        double scaleFactor = Mod::get()->getSettingValue<double>("hazard-scale-factor");
        bool tightenPortals = Mod::get()->getSettingValue<bool>("tighten-portals");

        log::info("Auto Buffer: Modifying level objects for level '{}'", level->m_levelName);

        // Access the array of objects in PlayLayer
        if (this->m_objects) {
            CCArray* objects = this->m_objects;
            size_t buffedCount = 0;

            for (int i = 0; i < objects->count(); i++) {
                auto obj = typeinfo_cast<GameObject*>(objects->objectAtIndex(i));
                if (!obj) continue;

                // Check object types (Spikes, Hazards, Saws)
                // GameObjectType::Hazard / Spike logic
                if (scaleHazards && (obj->m_objectType == GameObjectType::Hazard || obj->m_isSpike)) {
                    float currentScale = obj->getScale();
                    obj->setScale(currentScale * static_cast<float>(scaleFactor));
                    buffedCount++;
                }

                // Tighten portals by scaling them down slightly
                if (tightenPortals && obj->m_objectType == GameObjectType::Portal) {
                    float currentScale = obj->getScale();
                    obj->setScale(currentScale * 0.85f);
                    buffedCount++;
                }
            }

            log::info("Auto Buffer: Successfully buffed {} objects!", buffedCount);
        }

        return true;
    }
};

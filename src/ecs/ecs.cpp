#include <EngineToolkit/ecs/ecs.hpp>

namespace ECS {
    bool System::has_component(EntityID entity, ComponentID component) {
        Record &record = m_entities[entity];
        ArchetypeSet &archetype_set = m_components[component];
        return archetype_set.count(record.archetype) != 0;
    }

    std::any System::get_value(EntityID entity, ComponentID component) {
        Record &record = m_entities[entity];
        Archetype &archetype = m_archetypes[record.archetype];
        ArchetypeSet &archetype_set = m_components[component];

        if (archetype_set.count(record.archetype) == 0)
            // Component is not present
            return {};

        for (int i = 0; i < archetype.type.size(); i++) {
            if (archetype.type[i] == component)
                return archetype.columns[i][record.row];
        }

        return {};
    }

    EntityID System::add(const Type &type) {
        // Get / Create Archetype
        ArchetypeID archeID = query(type);
        if (archeID == 0) {
            // TODO proper error code
            // TODO generate archetype
        }

        // Preserve ID
        EntityID id;
        if (!unused.empty()) {
            id = unused.front();
            unused.pop_front();
        } else {
            id = cursor;
            cursor++;
        }

        return id;
    }

    bool System::del(EntityID entity) {
        if (m_entities.erase(entity)) {
            // Move back cursor if possible
            if (entity + 1 == cursor) {
                // TODO
            }
            unused.push_back(entity);
            return true;
        }

        return false;
    }

    Entity System::get(EntityID id) {
        const Record &record = m_entities[id];
        const Archetype &archetype = m_archetypes[record.archetype];

        Entity entity;
        for (ComponentID type: archetype.type) {
            // TODO poll value
        }

        return entity;
    }
}

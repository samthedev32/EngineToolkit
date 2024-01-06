#pragma once

#include <any>
#include <cstdint>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Optimization 1: query order
// keep track of how many entries each archetype has
// when query-ing an archetype, loop over the archetype
// with the least apperances, therefore less work must be done

namespace ECS {
    typedef uint16_t ComponentID;
    typedef uint32_t ArchetypeID;
    typedef uint64_t EntityID;

    typedef std::vector<ComponentID> Type;
    typedef std::vector<std::any> Column;

    struct Archetype {
        Type type; // Sorted array of components
        std::vector<Column> columns;
        // TODO fix deleted entities reordering vector
    };

    typedef std::unordered_set<ArchetypeID> ArchetypeSet;

    struct Record {
        ArchetypeID archetype;
        uint32_t row;
    };

    // Entity Reference
    typedef std::unordered_map<ComponentID, std::any &> Entity;

    class System {
    public:
        // Check if entity has component
        bool has_component(EntityID entity, ComponentID component);

        // Set value of entity's component
        bool set_value(EntityID entity, ComponentID component, std::any value);

        // Get value of entity's component
        std::any get_value(EntityID entity, ComponentID component);

        // ---- Entity Management

        // Add Entity
        EntityID add(const Type &type);

        // Delete Entity
        bool del(EntityID entity);

        // Get Entity Reference
        Entity get(EntityID entity);

        // TODO: load/save using sqlite

    private:
        std::vector<Archetype> m_archetypes;
        std::unordered_map<ComponentID, ArchetypeSet> m_components; // set of archetypes the components are in

        std::unordered_map<EntityID, Record> m_entities; // array of entities
        uint32_t cursor{}; // cursor to last free Element ID
        std::list<EntityID> unused; // list of free Element IDs

    private:
        ArchetypeID query(Type type);
    };
}

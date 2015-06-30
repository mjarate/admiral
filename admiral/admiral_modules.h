#include "admiral_modules_macros.h"

#define MODULE_ARG(CLASS,DISPLAY,DESC,TYPE,DEFVAL) class CLASS { \
    displayName = DISPLAY; \
    description = DESC; \
    typeName = TYPE; \
    defaultValue = DEFVAL; \
}

#define ZONE_NAME_ARG               MODULE_ARG(ZONE_NAME_ARG_CLASS,"Name","Global variable's name that equals to the zone object.","STRING","")
#define AXIS_A_ARG                  MODULE_ARG(AXIS_A_ARG_CLASS,"Axis A","Size of axis A in metres.","NUMBER",100)
#define AXIS_B_ARG                  MODULE_ARG(AXIS_B_ARG_CLASS,"Axis B","Size of axis B in metres.","NUMBER",100)
#define ANGLE_ARG                   MODULE_ARG(ANGLE_ARG_CLASS,"Angle","Angle of the zone.","NUMBER",0)
#define UNIT_TEMPLATE_ARG           MODULE_ARG(UNIT_TEMPLATE_ARG_CLASS,"Unit template","Unit template used by zone. Leave it empty to use default.","STRING","")
#define ZONE_TEMPLATE_ARG           MODULE_ARG(ZONE_TEMPLATE_ARG_CLASS,"Zone template","Zone template used by zone. Leave it empty to use default.","STRING","")
#define CQC_POOL_ARG                MODULE_ARG(CQC_POOL_ARG_CLASS,"Pool","Maximum number of CQC units to be spawned.","NUMBER",0)
#define MIN_HEIGHT_ARG              MODULE_ARG(MIN_HEIGHT_ARG_CLASS,"Minumum height","The minimum height CQC will spawn above.","NUMBER",0)
#define PATROL_INFANTRY_POOL_ARG    MODULE_ARG(PATROL_INFANTRY_POOL_ARG_CLASS,"Infantry pool","Number infantry groups to spawn.","NUMBER",0)
#define PATROL_TECHNICAL_POOL_ARG   MODULE_ARG(PATROL_TECHNICAL_POOL_ARG_CLASS,"Technical pool","Number technical groups to spawn.","NUMBER",0)
#define PATROL_ARMOUR_POOL_ARG      MODULE_ARG(PATROL_ARMOUR_POOL_ARG_CLASS,"Armour pool","Number armour groups to spawn.","NUMBER", 0)
#define CAMP_INFANTRY_POOL_ARG      MODULE_ARG(CAMP_INFANTRY_POOL_ARG_CLASS,"Infantry pool","Number infantry groups to spawn. (-1 for unlimited)","NUMBER",0)
#define CAMP_TECHNICAL_POOL_ARG     MODULE_ARG(CAMP_TECHNICAL_POOL_ARG_CLASS,"Technical pool","Number technical groups to spawn. (-1 for unlimited)","NUMBER",0)
#define CAMP_ARMOUR_POOL_ARG        MODULE_ARG(CAMP_ARMOUR_POOL_ARG_CLASS,"Armour pool","Number armour groups to spawn. (-1 for unlimited)","NUMBER", 0)
#define INFANTRY_WAVE_ARG           MODULE_ARG(INFANTRY_WAVE_ARG_CLASS,"Infantry wave","Number infantry groups to spawn in a wave.","NUMBER", 0)
#define TECHNICAL_WAVE_ARG          MODULE_ARG(TECHNICAL_WAVE_ARG_CLASS,"Technical wave","Number technical groups to spawn in a wave.","NUMBER", 0)
#define ARMOUR_WAVE_ARG             MODULE_ARG(ARMOUR_WAVE_ARG_CLASS,"Armour wave","Number armour groups to spawn in a wave.","NUMBER", 0)
#define CAMP_DELAY_ARG              MODULE_ARG(CAMP_DELAY_ARG_CLASS,"Camp delay","The delay in seconds the zone will do checks to spawn a group.","NUMBER", 10)
#define INFANTRY_GROUP_DELAY_ARG    MODULE_ARG(INFANTRY_GROUP_DELAY_ARG_CLASS,"Infantry group delay","Delay in seconds times Camp delay between infantry waves.","NUMBER", 0)
#define TECHNICAL_GROUP_DELAY_ARG   MODULE_ARG(TECHNICAL_GROUP_DELAY_ARG_CLASS,"Technical group delay","Delay in seconds times Camp delay between infantry waves.","NUMBER", 0)
#define ARMOUR_GROUP_DELAY_ARG      MODULE_ARG(ARMOUR_GROUP_DELAY_ARG_CLASS,"Armour group delay","Delay in seconds times Camp delay between infantry waves.","NUMBER", 0)
#define SPAWN_CHANCE_ARG            MODULE_ARG(SPAWN_CHANCE_ARG_CLASS,"Spawn chance","Chance from 0 to 100 percent to spawn a group.","NUMBER", 100)

#define SHAPE_ARG class SHAPE_ARG_CLASS { \
    displayName = "Shape"; \
    description = "Shape of the zone."; \
    typeName = "BOOL"; \
    class values { \
        class Ellipse { \
            name = "Ellipse"; \
            value = 0; \
            default = 1; \
        }; \
        class Rectangle { \
            name = "Rectangle"; \
            value = 1; \
        }; \
    }; \
}

#define ZONE_MODULE(CLASS,DISPLAY,ICON,FUNC,ARGS) class CLASS : Module_F { \
    scope = 2; \
    displayName = DISPLAY; \
    icon = ICON; \
    category = "Admiral"; \
    function = FUNC; \
    functionPriority = 1; \
    isGlobal = 1; \
    isTriggerActivated = 1; \
    ARGS; \
}

#define CQC_ARGS class Arguments { \
    ZONE_NAME_ARG; \
    AXIS_A_ARG; \
    AXIS_B_ARG; \
    ANGLE_ARG; \
    SHAPE_ARG; \
    CQC_POOL_ARG; \
    MIN_HEIGHT_ARG; \
    UNIT_TEMPLATE_ARG; \
    ZONE_TEMPLATE_ARG; \
}

#define PATROL_ARGS class Arguments { \
    ZONE_NAME_ARG; \
    AXIS_A_ARG; \
    AXIS_B_ARG; \
    ANGLE_ARG; \
    SHAPE_ARG; \
    PATROL_INFANTRY_POOL_ARG; \
    PATROL_TECHNICAL_POOL_ARG; \
    PATROL_ARMOUR_POOL_ARG; \
    UNIT_TEMPLATE_ARG; \
    ZONE_TEMPLATE_ARG; \
}

#define PERIODIC_CAMP_ARGS class Arguments { \
    ZONE_NAME_ARG; \
    AXIS_A_ARG; \
    AXIS_B_ARG; \
    ANGLE_ARG; \
    SHAPE_ARG; \
    CAMP_INFANTRY_POOL_ARG; \
    CAMP_TECHNICAL_POOL_ARG; \
    CAMP_ARMOUR_POOL_ARG; \
    INFANTRY_WAVE_ARG; \
    TECHNICAL_WAVE_ARG; \
    ARMOUR_WAVE_ARG; \
    INFANTRY_GROUP_DELAY_ARG; \
    TECHNICAL_GROUP_DELAY_ARG; \
    ARMOUR_GROUP_DELAY_ARG; \
    CAMP_DELAY_ARG; \
    UNIT_TEMPLATE_ARG; \
    ZONE_TEMPLATE_ARG; \
}

#define ONDEMAND_CAMP_ARGS class Arguments { \
    ZONE_NAME_ARG; \
    AXIS_A_ARG; \
    AXIS_B_ARG; \
    ANGLE_ARG; \
    SHAPE_ARG; \
    CAMP_INFANTRY_POOL_ARG; \
    CAMP_TECHNICAL_POOL_ARG; \
    CAMP_ARMOUR_POOL_ARG; \
    INFANTRY_WAVE_ARG; \
    TECHNICAL_WAVE_ARG; \
    ARMOUR_WAVE_ARG; \
    CAMP_DELAY_ARG; \
    UNIT_TEMPLATE_ARG; \
    ZONE_TEMPLATE_ARG; \
}

#define RANDOM_CAMP_ARGS class Arguments { \
    ZONE_NAME_ARG; \
    AXIS_A_ARG; \
    AXIS_B_ARG; \
    ANGLE_ARG; \
    SHAPE_ARG; \
    CAMP_INFANTRY_POOL_ARG; \
    CAMP_TECHNICAL_POOL_ARG; \
    CAMP_ARMOUR_POOL_ARG; \
    INFANTRY_WAVE_ARG; \
    TECHNICAL_WAVE_ARG; \
    ARMOUR_WAVE_ARG; \
    SPAWN_CHANCE_ARG; \
    CAMP_DELAY_ARG; \
    UNIT_TEMPLATE_ARG; \
    ZONE_TEMPLATE_ARG; \
}



class Logic;
class Module_F : Logic {
};

ZONE_MODULE(Admiral_CqcZone,"CQC Zone",ADDON_PATH(resources\module_icons\Cqc.paa),"adm_zone_initCqcZoneFromModule",CQC_ARGS);
ZONE_MODULE(Admiral_PatrolZone,"Patrol Zone",ADDON_PATH(resources\module_icons\Camp.paa),"adm_zone_initPatrolZoneFromModule",PATROL_ARGS);
ZONE_MODULE(Admiral_PeriodicCampZone,"Periodic Camp Zone",ADDON_PATH(resources\module_icons\Periodic.paa),"adm_zone_initPeriodicCampZoneFromModule",PERIODIC_CAMP_ARGS);
ZONE_MODULE(Admiral_OndemandCampZone,"Ondemand Camp Zone",ADDON_PATH(resources\module_icons\Ondemand.paa),"adm_zone_initOndemandCampZoneFromModule",ONDEMAND_CAMP_ARGS);
ZONE_MODULE(Admiral_RandomCampZone,"Random Camp Zone",ADDON_PATH(resources\module_icons\Random.paa),"adm_zone_initRandomCampZoneFromModule",RANDOM_CAMP_ARGS);
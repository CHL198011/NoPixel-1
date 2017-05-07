 class CfgPatches
 {
 	class sl_vehicles_red
 	{
 		units[] = {};
 		weapons[] = {};
 		requiredVersion = 0.1;
		requiredAddons[]= {
            "A3_Data_F",
            "sl_impala"
		};
 	};
 };
class cfgFunctions
{
	class Love
	{
		class Authors
		{
			file="\sl_vehicles_red";
			class WeLikeAuthors
			{
				preinit=1;
			};
		};
	};
};

class cfgVehicles
{
    class red_camaro_12_black;
	class red_charger_12_black;
	class red_charger_15_black;
	class red_corvette_14_black;
	class red_genesis_16_black;
	class red_gs350_13_black;
	class red_panamera_10_black;
	class red_porsche_12_black;
	class red_s65_12_black;
	class red_suburban_15_black;
	class red_taurus_10_black;
	class red_vanquish_13_black;
	class red_xkrs_12_black;
	class red_venomgt_11_black;
	class red_charger_15_base;

    //police vehicles
    class red_charger_15_p_p_base;
    class red_taurus_10_p_u_base;
    class red_charger_12_p_u_base;
    class red_charger_15_p_u_base;
    class red_explorer_16_p_p_base;
    class red_suburban_15_p_u_black;

    #include "\sl_vehicles_red\config\cfgCivilianVehicles.hpp"
    #include "\sl_vehicles_red\config\cfgSpecialVehicles.hpp"
    #include "\sl_vehicles_red\config\cfgPoliceVehicles.hpp"
};
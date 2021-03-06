class CfgPatches
{
	class red_porsche_12_pu
	{
		units[] = {"red_porsche_12_p_u"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Soft_F"};
	};
};

class CfgSounds
{
	sounds[] = {"Siren1","Siren2","Siren3", "ems_siren1", "ems_siren2", "ems_siren3"};
	class Siren1
	{
		name = "Siren1";
		sound[] = {"red_sounds\police\sounds\siren.wav",1,1};
		titles[] = {};
	};
	class Siren2
	{
		name = "Siren2";
		sound[] = {"red_sounds\police\sounds\yelp.wav",1,1};
		titles[] = {};
	};
};

class cfgWeapons
{
	class SportCarHorn;
	class red_horn_airhorn: SportCarHorn
	{
		displayname = "Airhorn";
		reloadTime = 4;
		drySound[] = {"red_sounds\police\sounds\FederalAirhorn.wav",1,1};
		scope = 2;
	};
	
	class red_horn_takedown1: SportCarHorn
	{
		displayName = "Takedown 1";
		reloadtime = 4;
		drysound[] = {"red_sounds\police\sounds\Takedown1.wav",1,1};
		scope = 2;
	};
	class red_horn_takedown2: SportCarHorn
	{
		displayName = "Takedown 2";
		reloadtime = 4;
		drysound[] = {"red_sounds\police\sounds\Takedown2.wav",1,1};
		scope = 2;
	};
	
	class red_horn_pullover: SportCarHorn
	{
		displayname = "Pull Over";
		reloadTime = 4;
		drySound[] = {"red_sounds\police\sounds\PullOver.wav",2,1};
		scope = 2;
	};

	class red_horn_handsup: SportCarHorn
	{
		displayName = "Hands Up";
		reloadtime = 4;
		drysound[] = {"red_sounds\police\sounds\HandsUp.wav",2,1};
		scope = 2;
	};
	
	class red_horn_passenger: SportCarHorn
	{
		displayName = "Passenger";
		reloadtime = 4;
		drysound[] = {"red_sounds\police\sounds\Passenger.wav",3,1};
		scope = 2;
	};
	
	class red_horn_driver: SportCarHorn
	{
		displayName = "Driver";
		reloadtime = 4;
		drysound[] = {"red_sounds\police\sounds\Driver.wav",3,1};
		scope = 2;
	};
};


class DefaultEventhandlers;
class cfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		class HitPoints;
		class NewTurret;
	};
	class Car_F: Car
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
			};
		};
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1{};
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
		};
		class EventHandlers;
		class AnimationSources;
	};
	class red_porsche_12_p_u_base: Car_F
	{
		model = "\red_porsche_12_pu\red_porsche_12_p_u";
		picture	= "\red_base\textures\icon.paa"; /// icon in map	
		Icon	= "\red_base\textures\icon.paa"; /// icon in map	
		author = "Redhotsteel";
		weapons[] = {"red_horn_airhorn","red_horn_takedown1","red_horn_takedown2","red_horn_pullover","red_horn_handsup","red_horn_driver","red_horn_passenger"};
		hiddenSelections[] = {
		"camo1",
		"lb_1_b",
		"lb_2_b",
		"lb_3_b",
		"lb_4_b",
		"lb_1_r",
		"lb_2_r",
		"lb_3_r",
		"lb_4_r",
		"back_light",
		"back_light_1",
		"reverse_light_lb",
		"reverse_light_lb_2",
		"D1",
		"D2",
		"D3",
		"D4",
		"D5",
		"D6",
		"D7",
		"D8",
		"lock1",
		"lock2",
		"lock3",
		"target1",
		"target2",
		"target3",
		"patrol1",
		"patrol2",
		"patrol3"
	};
		hiddenSelectionsTextures[] = {"\red_base\colours\red.paa"};
		terrainCoef = 1.0;
		turnCoef = 2.5;
		precision = 10;
		fireResistance = 5;
		armor = 32;
		cost = 50000;
		transportMaxBackpacks = 3;
		transportSoldier = 4;
		driveOnComponent[] = {"wheel_1_1_damper","wheel_1_2_damper","wheel_2_1_damper","wheel_2_2_damper"};
		extCameraPosition[] = {0, 1, -7.5};
		
		class eventhandlers
		{
			init = "_this execVM ""red_porsche_12_pu\scripts\init.sqf"";";
		};
		
		class UserActions
		{
			class codeone
			{
				displayName = "<t color='#0000ff'>Code One</t>";
				position = "drivewheel";
				radius = 2;
				condition = "driver this == player"; 
				statement = "this setVariable ['lightbar',0,true]; this setVariable ['siren',0,true]; this setVariable ['lights',0,true]; this setVariable ['directional',0,true]; this setVariable ['directional1',0,true]; this setVariable ['directional2',0,true]; this setVariable ['directional3',0,true]";
				onlyForplayer = 0;
			};
			class codetwo
			{
				displayName = "<t color='#0000ff'>Code Two</t>";
				position = "drivewheel";
				radius = 2;
				condition = "driver this == player && (this getVariable ['lightbar',0]) == 0 && (this getVariable ['directional3',0]) == 0";
				statement = "this setVariable ['lightbar',1,true]; this setVariable ['siren',0,true]; this setVariable ['lights',1,true]; this setVariable ['directional',0,true]; this setVariable ['directional1',0,true]; this setVariable ['directional2',0,true]; this setVariable ['directional3',1,true]";
				onlyForplayer = 0;
			};
			class codetwo2
			{
				displayName = "<t color='#0000ff'>Code Two</t>";
				position = "drivewheel";
				radius = 2;
				condition = "driver this == player && (this getVariable ['siren',0]) == 1 && (this getVariable ['directional3',0]) == 0";
				statement = "this setVariable ['lightbar',1,true]; this setVariable ['siren',0,true]; this setVariable ['lights',1,true]; this setVariable ['directional',0,true]; this setVariable ['directional1',0,true]; this setVariable ['directional2',0,true]; this setVariable ['directional3',1,true]";
				onlyForplayer = 0;
			};
			
			class sirenon
			{
				displayName = "<t color='#ff0000'>Code Three</t>";
				position = "drivewheel";
				radius = 2;
				condition = "driver this == player && (this getVariable ['siren',0]) == 0 && (this getVariable ['directional',0]) == 0";
				statement = "this setVariable ['lightbar',1,true]; this setVariable ['siren',1,true]; this setVariable ['directional',1,true]; this setVariable ['directional1',0,true]; this setVariable ['directional2',0,true]; this setVariable ['directional3',0,true]";
				onlyForplayer = 0;
			};
			
			class Reset
			{
				displayName="<t color='#ff0000'>Reset Lock/Fast</t>";
				position="drivewheel";
				radius=10;
				condition = "player IN this";
				statement="this setobjecttextureglobal [24,'\red_base\textures\emergency\pic0.paa']; this setobjecttextureglobal [25,'\red_base\textures\emergency\pic0.paa']; this setobjecttextureglobal [26,'\red_base\textures\emergency\pic0.paa']; Prevspeed = 0;";
				onlyForplayer=1;
			};
		};
		
		class HitPoints2
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
		};
		
		class AnimationSources;
		wheelDamageRadiusCoef = 0.9;
		wheelDestroyRadiusCoef = 0.4;
		maxFordingDepth = 0.5;
		waterResistance = 1;
		crewCrashProtection = 0.25;
		driverLeftHandAnimName = "drivewheel";
		driverRightHandAnimName = "drivewheel";
		class Turrets{};
		class HitPoints: HitPoints
		
		{
			class HitLFWheel: HitLFWheel
			{
				armor = 0.5;
				passThrough = 0;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor = 0.5;
				passThrough = 0;
			};
			class HitRFWheel: HitRFWheel
			{
				armor = 0.5;
				passThrough = 0;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor = 0.5;
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1.5;
				material = -1;
				name = "fueltank";
				visual = "";
				passThrough = 0.2;
			};
			class HitEngine
			{
				armor = 1.5;
				material = -1;
				name = "engine";
				visual = "";
				passThrough = 0.2;
			};
			class HitBody: HitBody
			{
				name = "body";
				visual = "camo1";
				passThrough = 1;
			};
			class HitGlass1: HitGlass1
			{
				armor = 0.75;
			};
			class HitGlass2: HitGlass2
			{
				armor = 0.75;
			};
			class HitGlass3: HitGlass3
			{
				armor = 0.75;
			};
			class HitGlass4: HitGlass4
			{
				armor = 0.75;
			};
			class HitGlass5: HitGlass5
			{
				armor = 0.75;
			};
			class HitGlass6: HitGlass6
			{
				armor = 0.75;
			};
		};
		
		driverAction = driver_low01; /// what action is going the driver take inside the vehicle. Non-existent action makes the vehicle inaccessible
		cargoAction[] = {passenger_low01,passenger_low01,passenger_low01};
		getInAction = "GetInLow"; 
		getOutAction = "GetOutLow"; 
		cargoGetInAction[] 	= {"GetInLow"}; 
		cargoGetOutAction[] = {"GetOutLow"};
		attenuationEffectType = "CarAttenuation";

		soundGetIn[]={"A3\Sounds_F\vehicles\soft\Hatchback_01\Hatchback_01_door",db-5,1};
		soundGetOut[]={"A3\Sounds_F\vehicles\soft\Hatchback_01\Hatchback_01_door",db-5,1, 40};
		soundDammage[]={"", db-5, 1};
		soundEngineOnInt[] = {"red_base\sounds\SPORTS_V8\int-start", db-8, 1.0};
		soundEngineOnExt[] = {"red_base\sounds\SPORTS_V8\ext-start", db-7, 1.0, 200};
		soundEngineOffInt[] = {"red_base\sounds\SPORTS_V8\int_stop", db-8, 1.0};
		soundEngineOffExt[] = {"red_base\sounds\SPORTS_V8\ext_stop", db-7, 1.0, 200};

		buildCrash0[]={"A3\Sounds_F\vehicles\soft\noises\crash_building_01", db-3, 1,200};
		buildCrash1[]={"A3\Sounds_F\vehicles\soft\noises\crash_building_02", db-3, 1,200};
 		buildCrash2[]={"A3\Sounds_F\vehicles\soft\noises\crash_building_03", db-3, 1,200};
 		buildCrash3[]={"A3\Sounds_F\vehicles\soft\noises\crash_building_04", db-3, 1,200};
 		soundBuildingCrash[]={buildCrash0, 0.25, buildCrash1, 0.25, buildCrash2, 0.25, buildCrash3, 0.25};

		WoodCrash0[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_01", db-3, 1,200};
		WoodCrash1[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_02", db-3, 1,200};
		WoodCrash2[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_03", db-3, 1,200};
		WoodCrash3[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_04", db-3, 1,200};
		WoodCrash4[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_05", db-3, 1,200};
		WoodCrash5[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_06", db-3, 1,200};
		soundWoodCrash[]={woodCrash0, 0.166, woodCrash1, 0.166, woodCrash2, 0.166, woodCrash3, 0.166,woodCrash4, 0.166,woodCrash5, 0.166};

		ArmorCrash0[]={"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_01", db-3, 1,200};
		ArmorCrash1[]={"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_02", db-3, 1,200};
		ArmorCrash2[]={"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_03", db-3, 1,200};
		ArmorCrash3[]={"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_04", db-3, 1,200};
		soundArmorCrash[]={ArmorCrash0, 0.25, ArmorCrash1, 0.25, ArmorCrash2, 0.25, ArmorCrash3, 0.25};

		class	Sounds
		{
			// warp	factor
			#define	FACTOR(val,from,to)	(val factor[from,to])
			// RANGE(val,	begin, band, end,	band)
			#define	RANGE(val,from,band0,to,band1) FACTOR2(val,from,(from+band0),to,(to+band1))
			// FACTOR2(val,	0, 400,	1200,	2000)
			#define	FACTOR2(val,from0,to0,from1,to1) (FACTOR(val,from0,to0)	*	FACTOR(val,to1,from1))

			// redRpm
			#define	MAX_RPM	6900
			// scaled	rpm	to 0 - 1
			#define	RPM(rpm) (rpm/MAX_RPM)

			// specialized FACTOR	for	rpm
			#define	FACTOR_RPM(from,to)	FACTOR(RPM(rpm),RPM(from),RPM(to))
			// specialized peak	for	rpm
			#define	FACTOR2_RPM(from0,to0,from1,to1) (FACTOR_RPM(from0,to0)	*	FACTOR_RPM(to1,from1))
			// specialized peak, different definition, version for rpm
			#define	RANGE_RPM(from,band0,to,band1) FACTOR2_RPM(from,(from+band0),to,(to+band1))
			

			#define HZ_IDLE FACTOR_RPM(400,1150)
			#define HZ_RPM1 FACTOR_RPM(900,2100)
			#define HZ_RPM2	FACTOR_RPM(1300,3100)
			#define HZ_RPM3 FACTOR_RPM(2200,4100)
			#define HZ_RPM4 FACTOR_RPM(3300,4900)
			#define HZ_RPM5 FACTOR_RPM(4200,6200)
			#define HZ_RPM6 FACTOR_RPM(5100,6900)
			
			#define VOLUME_IDLE FACTOR2_RPM(400,700,900,1100)
			#define VOLUME_RPM1 FACTOR2_RPM(870,1100,1300,2100)
			#define VOLUME_RPM2 FACTOR2_RPM(1250,2050,2300,3100)
			#define VOLUME_RPM3 FACTOR2_RPM(2250,3050,3300,4100)
			#define VOLUME_RPM4 FACTOR2_RPM(3250,4050,4200,4870)
			#define VOLUME_RPM5 FACTOR2_RPM(4150,4800,5150,6150)
			#define VOLUME_RPM6 FACTOR_RPM(5100,6100)

			class	Idle_ext
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\int_idle", db-13,	1, 150};
				frequency	=	0.9	+	HZ_IDLE*0.2;
				volume = engineOn*camPos*VOLUME_IDLE;
			};
			class	Engine
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\ext_1000",	db-11,1, 200};
				frequency	=	0.8	+	HZ_RPM1*0.2;
				volume = engineOn*camPos*VOLUME_RPM1;
			};
			class	Engine1_ext
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\ext_2000",	db-9,1, 240};
				frequency	=	0.8	+	HZ_RPM2*0.2;
				volume = engineOn*camPos*VOLUME_RPM2;
			};
			class	Engine2_ext
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\ext_3000",	db-8,1, 280};
				frequency	=	0.8	+	HZ_RPM3*0.2;
				volume = engineOn*camPos*VOLUME_RPM3;
			};
			class	Engine3_ext
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\ext_4000",	db-7,1, 320};
				frequency	=	0.8	+	HZ_RPM4*0.2;
				volume = engineOn*camPos*VOLUME_RPM4;
			};
			class	Engine4_ext
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\ext_5000",	db-6,1, 360};
				frequency	=	0.8	+	HZ_RPM5*0.2;
				volume = engineOn*camPos*VOLUME_RPM5;
			};
			class	Engine5_ext
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\ext_6000",	db-5,1, 420};
				frequency	=	0.95	+	HZ_RPM6*0.15;
				volume = engineOn*camPos*VOLUME_RPM6;
			};
			
				/*   POD PLYNEM EXTERNI  */
				
			class IdleThrust
			{
				sound[] = {"red_base\sounds\SPORTS_V8\ext_idle", db-6,1, 200};
				frequency	=	0.9	+	HZ_IDLE*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_IDLE;
			};
			
			class EngineThrust
			{
				sound[] = {"red_base\sounds\SPORTS_V8\ext_1000", db-5,1, 250};
				frequency	=	0.8	+	HZ_RPM1*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM1;
			};
			
			class Engine1_Thrust_ext
			{
				sound[] = {"red_base\sounds\SPORTS_V8\ext_2000", db-4,1, 280};
				frequency	=	0.8	+	HZ_RPM2*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM2;
			};
			
			class Engine2_Thrust_ext
			{
				sound[] = {"red_base\sounds\SPORTS_V8\ext_3000", db-3,1, 320};
				frequency	=	0.8	+	HZ_RPM3*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM3;
			};
			
			class Engine3_Thrust_ext
			{
				sound[] = {"red_base\sounds\SPORTS_V8\ext_4000", db-2,1, 360};
				frequency	=	0.8	+	HZ_RPM4*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM4;
			};
			
			class Engine4_Thrust_ext
			{
				sound[] = {"red_base\sounds\SPORTS_V8\ext_5000", db0,1, 400};
				frequency	=	0.8	+	HZ_RPM5*0.3;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM5;
			};
			
			class Engine5_Thrust_ext
			{
				sound[] = {"red_base\sounds\SPORTS_V8\ext_6000", db2,1, 450};
				frequency	=	0.9	+	HZ_RPM6*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM6;
			};  

			class	Idle_int
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\int_idle", db-15,	1};
				frequency	=	0.9	+	HZ_IDLE*0.2;
				volume = engineOn*(1-camPos)*VOLUME_IDLE;
			};
			
			class	Engine_int
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\int_1000",	db-14,1 };
				frequency	=	0.8	+	HZ_RPM1*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM1;
			};
			
			class	Engine1_int
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\int_2000",	db-12,1 };
				frequency	=	0.8	+	HZ_RPM2*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM2;
			};
			
			class	Engine2_int
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\int_3000",	db-11,1 };
				frequency	=	0.8	+	HZ_RPM3*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM3;
			};
			
			class	Engine3_int
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\int_4000",	db-10,1 };
				frequency	=	0.8	+	HZ_RPM4*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM4;
			};
			
			class	Engine4_int
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\int_5000",	db-9,1 };
				frequency	=	0.8	+	HZ_RPM5*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM5;
			};
			
			class	Engine5_int
			{
				sound[]	=	{"red_base\sounds\SPORTS_V8\int_6000",	db-6,1 };
				frequency	=	0.95	+	HZ_RPM6*0.15;
				volume = engineOn*(1-camPos)*VOLUME_RPM6;
			};

			class IdleThrust_int
			{
				sound[] = {"red_base\sounds\SPORTS_V8\int_idle", db-10,1 };
				frequency	=	0.9	+	HZ_IDLE*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_IDLE;
			};
			
			class EngineThrust_int
			{
				sound[] = {"red_base\sounds\SPORTS_V8\int_1000", db-9,1 };
				frequency	=	0.8	+	HZ_RPM1*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM1;
			};
			
			class Engine1_Thrust_int
			{
				sound[] = {"red_base\sounds\SPORTS_V8\int_2000", db-8,1 };
				frequency	=	0.8	+	HZ_RPM2*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM2;
			};
			
			class Engine2_Thrust_int
			{
				sound[] = {"red_base\sounds\SPORTS_V8\int_3000", db-7,1 };
				frequency	=	0.8	+	HZ_RPM3*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM3;
			};
			
			class Engine3_Thrust_int
			{
				sound[] = {"red_base\sounds\SPORTS_V8\int_4000", db-6,1 };
				frequency	=	0.8	+	HZ_RPM4*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM4;
			};
			
			class Engine4_Thrust_int
			{
				sound[] = {"red_base\sounds\SPORTS_V8\int_5000", db-5,1 };
				frequency	=	0.8	+	HZ_RPM5*0.3;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM5;
			};
			
			class Engine5_Thrust_int
			{
				sound[] = {"red_base\sounds\SPORTS_V8\int_6000", db-4,1 };
				frequency	=	0.9	+	HZ_RPM6*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM6;
			};
			
			class	Movement
			{
				sound	=	"soundEnviron";
				frequency	=	"1";
				volume = "0";
			};

			class TiresRockOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1", db-6, 1.0, 60};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			
			class TiresSandOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1", db-6, 1.0, 60};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			
			class TiresGrassOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2", db-6, 1.0, 60};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			
			class TiresMudOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2", db-6, 1.0, 60};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			
			class TiresGravelOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1", db-6, 1.0, 60};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			
			class TiresAsphaltOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2", db-6, 1.0, 60};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			
			class NoiseOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3", db-8, 1.0, 90};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
					
			class TiresRockIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1", db-6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			
			class TiresSandIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2", db-6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			
			class TiresGrassIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2", db-6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			
			class TiresMudIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2", db-6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			
			class TiresGravelIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1", db-6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			
			class TiresAsphaltIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2", db-6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			
			class NoiseIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3", db-12, 1.0};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)"; //definice INSIDE zvuku
			};
			
			class breaking_ext_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04", db-3, 1, 80};
				frequency	=	1;
				volume = engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};	
			
			class acceleration_ext_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db-3, 1, 80};
				frequency	=	1;
				volume = engineOn*camPos*asphalt*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
			};	
			
			class turn_left_ext_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db-3, 1, 80};
				frequency	=	1;
				volume = engineOn*camPos*asphalt*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
			};	

			class turn_right_ext_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db-3, 1, 80};
				frequency	=	1;
				volume = engineOn*camPos*asphalt*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};	
	
			class breaking_ext_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking", db-3, 1, 60};
				frequency	=	1;
				volume = engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15]);
			};	
			
			class acceleration_ext_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration", db-3,	1, 60};
				frequency	=	1;
				volume = engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1]);
			};	
			
			class turn_left_ext_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", db-3, 1, 60};
				frequency	=	1;
				volume = engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15]);
			};	

			class turn_right_ext_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", db-3, 1, 60};
				frequency	=	1;
				volume = engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15]);
			};	

			class breaking_int_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};	
			
			class acceleration_int_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
			};
			
			class turn_left_int_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
			};
			
			class turn_right_int_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};	
			
			class breaking_int_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-01, -0.4])*(Speed Factor[2, 15]);
			};	
			
			class acceleration_int_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
			};	
			
			class turn_left_int_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", db-10,	1};
				frequency	=	1;
				volume = engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
			};
			
			class turn_right_int_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", db-10,	1};
				frequency	=	1;
				volume = engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};
		};
		
		class RenderTargets
		{
			class LeftMirror
			{
				renderTarget = "rendertarget0";
				class CameraView1
				{
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 0;
					fov = 0.7;
				};
			};
			class RearCam
			{
				renderTarget = "rendertarget1";
				class CameraView1
				{
					pointPosition = "PIP1_pos";
					pointDirection = "PIP1_dir";
					renderQuality = 2;
					renderVisionMode = 0;
					fov = 0.7;
				};
			};
			class FrontCam
			{
				renderTarget = "rendertarget2";
				class CameraView1
				{
					pointPosition = "PIP2_pos";
					pointDirection = "PIP2_dir";
					renderQuality = 2;
					renderVisionMode = 0;
					fov = 0.7;
				};
			};
		};

		thrustDelay = 0.1;
		brakeIdleSpeed = 1.78;
		maxSpeed = 350;	// max speed on level road, km/h
		fuelCapacity = 45;
		wheelCircumference = 2.277;
		antiRollbarForceCoef = 2.0;
		antiRollbarForceLimit = 2.0;
		antiRollbarSpeedMin = 20;
		antiRollbarSpeedMax = 80;
		idleRpm = 900;
		redRpm = 6500;
		
		class complexGearbox {
			GearboxRatios[] = {"R1", -3.231, "N", 0, "D1", 4.462, "D2", 3.57, "D3", 2.571, "D4", 1.97, "D5", 1.601, "D6", 0.9, "D7", 0.65};
			TransmissionRatios[] = {"High", 4.111};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
			transmissionDelay = 0.01;
		};
		
		simulation = "carx";
		dampersBumpCoef = 0.01;
		differentialType = "rear_limited";
		frontRearSplit = 0.3;
		frontBias = 1.5;
		rearBias = 1.5;
		centreBias = 2.5;
		clutchStrength = 55.0;
		maxOmega = 680.68;
		enginePower = 462;
		peakTorque = 850;
		dampingRateFullThrottle = 0.03;
		dampingRateZeroThrottleClutchEngaged = 0.35;
		dampingRateZeroThrottleClutchDisengaged = 0.05;
		torqueCurve[] = {{0.0, 0.0}, {0.2, 0.65}, {0.3, 0.8}, {0.4, 0.95}, {0.6, 1.0}, {0.7, 0.95}, {0.9, 0.9}, {1.0, 0.5}};
		changeGearMinEffectivity[] = {0.95, 0.15, 0.98, 0.98, 0.98, 0.98, 0.97, 0.95, 0.95};
		switchTime = 0.20;
		latency = 0.8;
		
		class Wheels
		{
			class LF
			{
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				mass = 20;
				MOI = 5.3;
				maxBrakeTorque = 5000;
				suspTravelDirection[] = {0,-1,0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.15;
				mMaxDroop = 0.20;
				sprungMass = 273; 
				springStrength = 9813; //6813
				springDamperRate = 2500; //1091
				longitudinalStiffnessPerUnitGravity = 4800;
				latStiffX = 25;
				latStiffY = 220;
				frictionVsSlipGraph[] = {{0,1},{0.5,1},{1,1}};
			};
			class LR: LF
			{
				boneName = "wheel_1_2_damper";
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				steering = 0;
				side = "left";
				latStiffX = 25;
				latStiffY = 22000;
				maxHandBrakeTorque = 2500;
			};
			class RF: LF
			{
				boneName = "wheel_2_1_damper";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";

				steering = 1;
				side = "right";
				latStiffX = 25;
				latStiffY = 220;
			};
			class RR: RF
			{
				boneName = "wheel_2_2_damper";
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 2500;
				steering = 0;
				side = "right";
				latStiffX = 25;
				latStiffY = 22000;
			};
		};
		
		class Exhausts /// specific exhaust effects for the car
		{
			class Exhaust1 /// the car has two exhausts - each on one side
			{
				position 	= "exhaust1_pos";  		/// name of initial memory point
				direction 	= "exhaust1_dir";	/// name of memory point for exhaust direction
				effect 		= "ExhaustsEffect";	/// what particle effect is it going to use
			};

			class Exhaust2
			{
				position 	= "exhaust2_pos";
				direction 	= "exhaust2_dir";
				effect 		= "ExhaustsEffect";
			};				
		};

		class Reflectors	/// only front lights are considered to be reflectors to save CPU
		{
			class LightCarHeadL01 	/// lights on each side consist of two bulbs with different flares
			{
				color[] 		= {1550, 1550, 2000};		/// approximate colour of standard lights
				ambient[]		= {5, 5, 5};				/// nearly a white one
				position 		= "LightCarHeadL01";		/// memory point for start of the light and flare
				direction 		= "LightCarHeadL01_end";	/// memory point for the light direction
				hitpoint 		= "Light_L";				/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection 		= "Light_L";				/// selection for artificial glow around the bulb, not much used any more
				size 			= 1;						/// size of the light point seen from distance
				innerAngle 		= 100;						/// angle of full light
				outerAngle 		= 179;						/// angle of some light
				coneFadeCoef 	= 10;						/// attenuation of light between the above angles
				intensity 		= 1;						/// strength of the light
				useFlare 		= true;						/// does the light use flare?
				dayLight 		= false;					/// switching light off during day saves CPU a lot
				flareSize 		= 0.5;						/// how big is the flare

				class Attenuation
				{
					start 			= 1.0;
					constant 		= 0; 
					linear 			= 0; 
					quadratic 		= 0.25; 
					hardLimitStart 	= 30;		/// it is good to have some limit otherwise the light would shine to infinite distance
					hardLimitEnd 	= 60;		/// this allows adding more lights into scene
				};
			};

			class LightCarHeadR01: LightCarHeadL01
			{
				position 	= "LightCarHeadR01";
				direction 	= "LightCarHeadR01_end";
				hitpoint 	= "Light_R";
				selection 	= "Light_R";
			};
		};
		aggregateReflectors[] = {{"LightCarHeadL01"}, {"LightCarHeadR01"}}; /// aggregating reflectors helps the engine a lot
	};
	
	class red_porsche_12_p_u_black:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Black)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\black.paa"};
	};
	
	class red_porsche_12_p_u_aqua:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Aqua)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\aqua.paa"};
	};
	
	class red_porsche_12_p_u_darkblue:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Dark Blue)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\darkblue.paa"};
	};
	
	class red_porsche_12_p_u_green:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Green)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\green.paa"};
	};
	
	class red_porsche_12_p_u_red:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Red)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\red.paa"};
	};
	
	class red_porsche_12_p_u_pink:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Pink)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\pink.paa"};
	};
	
	class red_porsche_12_p_u_yellow:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Yellow)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\yellow.paa"};
	};
	
	class red_porsche_12_p_u_orange:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Orange)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\orange.paa"};
	};
	
	class red_porsche_12_p_u_white:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (White)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\white.paa"};
	};
	
	class red_porsche_12_p_u_purple:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Purple)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\purple.paa"};
	};
	
	class red_porsche_12_p_u_darkgreen:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Dark Green)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\darkgreen.paa"};
	};
	
	class red_porsche_12_p_u_darkred:red_porsche_12_p_u_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2012 Porsche GT2 RS (Dark Red)(P)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"red_base\colours\darkred.paa"};
	};
	
	class red_porsche_12_p_u_custom1: red_porsche_12_p_u_base
	{
		scope = 2;
		displayName = "2012 Porsche GT2 RS (Custom 1)(P)";
		crew = "C_man_1";
		side = 3;
		faction = "CIV_F";
		hiddenSelectionsTextures[] = {"\red_config\red_porsche_12_pu\skins\custom1.paa"};
	};
	class red_porsche_12_p_u_custom2: red_porsche_12_p_u_base
	{
		scope = 2;
		displayName = "2012 Porsche GT2 RS (Custom 2)(P)";
		crew = "C_man_1";
		side = 3;
		faction = "CIV_F";
		hiddenSelectionsTextures[] = {"\red_config\red_porsche_12_pu\skins\custom2.paa"};
	};
	class red_porsche_12_p_u_custom3: red_porsche_12_p_u_base
	{
		scope = 2;
		displayName = "2012 Porsche GT2 RS (Custom 3)(P)";
		crew = "C_man_1";
		side = 3;
		faction = "CIV_F";
		hiddenSelectionsTextures[] = {"\red_config\red_porsche_12_pu\skins\custom3.paa"};
	};
	
	class red_porsche_12_p_u_custom4: red_porsche_12_p_u_base
	{
		scope = 2;
		displayName = "2012 Porsche GT2 RS (Custom 4)(P)";
		crew = "C_man_1";
		side = 3;
		faction = "CIV_F";
		hiddenSelectionsTextures[] = {"\red_config\red_porsche_12_pu\skins\custom4.paa"};
	};
	
	class red_porsche_12_p_u_custom5: red_porsche_12_p_u_base
	{
		scope = 2;
		displayName = "2012 Porsche GT2 RS (Custom 5)(P)";
		crew = "C_man_1";
		side = 3;
		faction = "CIV_F";
		hiddenSelectionsTextures[] = {"\red_config\red_porsche_12_pu\skins\custom5.paa"};
	};
};
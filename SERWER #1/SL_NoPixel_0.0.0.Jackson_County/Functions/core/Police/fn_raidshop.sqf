_player = _this select 0;

if(player distance myshop < 100) then {

	[player] remoteExec ["StanLakesideServer_fnc_retreiveStoreCop",2];
	if (myjob == "cop") then {
	[_player,player,13,format ["%1 przeszukał sklep %2", name _player, name player],""] remoteExec ["StanLakesideServer_fnc_copLog", 2];
	};
} else {

	[myshop,"Lokalizacja sklepu","Job"] remoteexec ["StanLakeside_fnc_hudHelper",_player];
	
};
if (myjob == "Cop" || myjob == "EMS" || myjob == "Fire") exitWith {};
_class1 = ["kif_500k"];  
_class2 = ["kif_100k"]; 
_class3 = ["kif_50k"]; 
_total = 0;
_cashout = 0;

{
	_mag = _x;
	if(_mag IN _class1) then { _cashout = _cashout + 500000; player removeMagazine _mag; _total = _total + 1; };
	if(_mag IN _class2) then { _cashout = _cashout + 100000; player removeMagazine _mag; _total = _total + 1; };
	if(_mag IN _class3) then { _cashout = _cashout + 50000; player removeMagazine _mag; _total = _total + 1; };

} forEach magazines player;


[_cashout] call Client_fnc_addCash;

//["Sukces",format["Sprzedałeś narkotyki za: $%1", _cashout],[0,255,0,1],""] call Client_fnc_showNotification;
//[player,objNull,3,format ["%1 sprzedał NARKOTYKI w ilości %2 za %3 $", name player, _total, _cashout],_cashout, "NARKOTYKI", _total] remoteExec ["server_fnc_economyLog", 2];
//hint format["Zarobiłeś $%1.",_cashout];

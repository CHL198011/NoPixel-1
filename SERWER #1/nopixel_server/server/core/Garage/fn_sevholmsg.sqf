params ["_fura","_player"];

//_fura = _this select 0;
//_player = _this select 1;

_fura = _fura getvariable "information";
 
[_fura,_player] remoteexec ["StanLakesideClient_fnc_clholmsg",_player]; 

diag_log format["srvhol, player = ",_player];
diag_log format["srvhol, fura = ",_fura];
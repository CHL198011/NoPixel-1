_remove = call compile format["%1",(lbData[9001,(lbCurSel 9001)])];
["Remove","license",_remove] remoteexec ["StanLakesideClient_fnc_sustain",currentcursortarget];
closedialog 0;
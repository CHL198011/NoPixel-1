{
    //_phoneBackground = _x getVariable "phoneBackground";
    _messages = _x getVariable "messages";
    _statuses = _x getVariable "statuses";
    //_house = _x getVariable "house";
    //_shop = _x getVariable "shop";

    _houselevel = _x getVariable "houselevel";

    //_housecontent = _x getVariable "housecontent";
    //_shopcontent = _x getVariable "shopcontent";

    _cash = _x getVariable "wallet";
    _bank = _x getVariable "atm";

    _position = position _x;

    //_items = _x getVariable "getunitloadout";
	_items = getunitloadout _x;
	
    _uid = getplayerUID _x;

    _syncInfo = _x getVariable ["sync", 1];

    if(_syncInfo == 0 || _x in currentCop || _x in currentEMS || _x in currentFire) then { 
    _updatestr = format ["updatePlayerInfoNoGearNoShopNoHouse:%1:%2:%3:%4:%5:%6:%7", _cash, _bank, _position, _messages, _houselevel, _statuses _uid]; 
	_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;

	//_updatestr = format ["updatePlayerInfoNoGear:%1:%2:%3:%4:%5:%6:%7:%8:%9:%10", _cash, _bank, _position, _messages, _statuses, _housecontent, _shopcontent, _phonebackground, _houselevel, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerInfoNoGearNoMoneyNoShop:%1:%2:%3:%4:%5:%6", _position, _messages, _statuses, _phonebackground, _houselevel, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerHouseShop:%1:%2:%3", _housecontent, _shopcontent, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerMoney:%1:%2:%3", _cash, _bank, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;

} else { 
	_updatestr = format ["updatePlayerInfoNoShopNoHouse:%1:%2:%3:%4:%5:%6:%7:%8", _items, _cash, _bank, _position, _messages, _houselevel, _statuses, _uid]; 
	_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;

    //_updatestr = format ["updatePlayerInfo:%1:%2:%3:%4:%5:%6:%7:%8:%9:%10:%11", _items, _cash, _bank, _position, _messages, _statuses, _housecontent, _shopcontent, _phonebackground, _houselevel, _uid]; 
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerInfoNoGearNoMoneyNoShop:%1:%2:%3:%4:%5:%6", _position, _messages, _statuses, _phonebackground, _houselevel, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerHouseShop:%1:%2:%3", _housecontent, _shopcontent, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerMoney:%1:%2:%3", _cash, _bank, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//[_player,_items, _uid] spawn server_fnc_invSave;
    };

    /*if (_houseLevel == 1) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 2) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 3) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 4) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 5) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 6) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 7) then {
        tier3housing pushback _house;
    };
    if (_houseLevel == 8) then {
        tier3housing pushback _house;
    };
    if (_houseLevel == 9) then {
        tier3housing pushback _house;
    };*/
	diag_log "server_fnc_statSaveLoop";
} forEach allPlayers;
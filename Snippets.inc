//Useful snippets by Rogue 2018/2/20
//Get Weapon Slot from id:
stock GetWeaponSlot(weaponid) 
{ 
    switch(weaponid) 
    { 
        case 0..1:   return 0;
        case 2..9:   return 1;
        case 22..24: return 2;
        case 25..27: return 3;
        case 28..29: return 4;
        case 32:     return 4;
        case 30..31: return 5;
        case 33..34: return 6;
        case 35..38: return 7;
        case 16..18: return 8;
        case 39:     return 8;
        case 41..43: return 9;
        case 10..15: return 10;
        case 44..46: return 11;
        case 40: 	 return 12;
    } 
    return -1; 
}
//***************************************//
//Loop no-driver vehicles:
stock LoopNDCars() 
{ 
    new AllVehicles[MAX_VEHICLES]; 
    new PPVEH;
    for(new i, j = GetPlayerPoolSize(); i <= j; i++)  
    {
        PPVEH = GetPlayerVehicleID(i);
        if(!IsPlayerConnected(i)) continue; 
        if(GetPlayerState(i)== PLAYER_STATE_DRIVER && AllVehicles[PPVEH] != i ) AllVehicles[PPVEH]= i; 
    } 
    for(new x; x<MAX_VEHICLES; x++) 
    { 
        if(!IsValidVehicle(x)) continue; 
        if(AllVehicles[x] != -1 && GetPlayerState(AllVehicles[x]) != PLAYER_STATE_DRIVER) AllVehicles[x] = -1; 
        if(AllVehicles[x] == -1) 
        { 
            //This will get called for all cars that have no driver. 
        } 
    } 
    return 1; 
}
//***************************************//
//Anti-hacked samp clients:
stock IsPlayerBot(playerid)
{  
    new TempId[80], TempNumb;  
    gpci(playerid, TempId, sizeof(TempId));  
    for(new i = 0; i < strlen(TempId); i++)  
    {  
        if(TempId[i] >= '0' && TempId[i] <= '9')  TempNumb++;  
    }  
    return (TempNumb >= 30 || strlen(TempId) <= 30) ? true : false;
}
//***************************************//
//Check for under water players:
stock IsPlayerUnderWater(playerid)
{
    new PPAnim = GetPlayerAnimationIndex(playerid);
    return (PPAnim == 1540 || PPAnim == 1544) ? true : false;
}  
//***************************************//

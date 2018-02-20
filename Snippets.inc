//Useful snippets by Rogue 2018/2/20
//Get Weapon Slot from id:
stock GetWeaponSlot(weaponid) 
{ 
    new slotid; 
    switch(weaponid) 
    { 
        case 0..1: 
        { 
            slotid = 0; 
            } 
        case 2..9: 
        { 
            slotid = 1; 
            } 
        case 22..24: 
        { 
            slotid = 2; 
            } 
        case 25..27: 
        { 
            slotid = 3; 
            } 
        case 28..29: 
        { 
            slotid = 4; 
            } 
        case 32: 
        { 
            slotid = 4; 
            } 
        case 30..31: 
        { 
            slotid = 5; 
            } 
        case 33..34: 
        { 
            slotid = 6; 
            } 
        case 35..38: 
        { 
            slotid = 7; 
            } 
        case 16..18: 
        { 
            slotid = 8; 
            } 
        case 39: 
        { 
            slotid = 8; 
            } 
        case 41..43: 
        { 
            slotid = 9; 
            } 
        case 10..15: 
        { 
            slotid = 10; 
            } 
        case 44..46: 
        { 
            slotid = 11; 
            } 
        case 40: 
        { 
            slotid = 12; 
            } 
        } 
    return slotid; 
}
//***************************************//
//Loop no-driver vehicles:
stock LoopNDCars() 
{ 
    new AllVehicles[MAX_VEHICLES]; 
    for(new i, j = GetPlayerPoolSize(); i <= j; i++)  
    { 
        if(!IsPlayerConnected(i)) continue; 
        if(GetPlayerState(i)== PLAYER_STATE_DRIVER && AllVehicles[GetPlayerVehicleID(i)] != i ) AllVehicles[GetPlayerVehicleID(i)]= i; 
        } 
    for(new x=0; x<MAX_VEHICLES; x++) 
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
        if(TempId[i] >= '0' && TempId[i] <= '9')  
        {  
             TempNumb++;  
            }  
        }  
    if(TempNumb >= 30 || strlen(TempId) <= 30)
    {
        return 1;
        }
    return 0;  
}

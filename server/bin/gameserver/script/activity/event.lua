-- lua script
module (..., package.seeall)

function CheckTriggerAbyss(role, occurst, timediff, percent, res)
    --percent = 100;
    --res.value = 0;
    res.value = role:CallLuaCheckAbyss(tonumber(occurst), tonumber(timediff), tonumber(percent))
end


-- lua script
module (..., package.seeall)

function upitemper(rolename, tid)
    local role = FindRoleByName(rolename)
    if role ~= nil then
        local item = role:FindItemByTID(tonumber(tid))
        if item ~= nil then
            role:UpItemPer(item)
        end
    end
end

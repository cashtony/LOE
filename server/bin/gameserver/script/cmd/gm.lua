-- lua script
module (..., package.seeall)

function addmoney(gmlevel, rolename, money)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddMoney(tonumber(money))
    end
end

function submoney(gmlevel, rolename, money)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:CostMoney(tonumber(money))
    end
end

function addcash(gmlevel, rolename, cash)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddRMB(0, tonumber(cash))
    end
end

function addnoncash(gmlevel, rolename, cash)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddCash(tonumber(cash), true)
    end
end

function subcash(gmlevel, rolename, cash)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:CostCash(tonumber(cash), false)
    end
end

function subnoncash(gmlevel, rolename, cash)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:CostCash(tonumber(cash), true)
    end
end

function addexp(gmlevel, rolename, exp)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddExp(tonumber(exp))
    end
end

function additem(gmlevel, rolename, tid, count)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddItem(tonumber(tid), tonumber(count))
    end
end

function addrmb(gmlevel, rolename, rmbcount, cashcount)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local cashtmp = 0
    if cashcount == nil then
        cashtmp = rmbcount * 10
    else
        cashtmp = tonumber(cashcount)
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddRMB(tonumber(rmbcount), tonumber(cashtmp))
    end
end

function resetepreceive(gmlevel, rolename)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:ResetEPReceive()
    end
end

function setgmlevel(gmlevel, rolename, level)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:SetGMLevel(tonumber(level))
    end
end

function addep(gmlevel, rolename, ep)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddEP(tonumber(ep))
    end
end

function addvipep(gmlevel, rolename, ep)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddVipEP(tonumber(ep))
    end
end

function costep(gmlevel, rolename, ep)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:CostEP(tonumber(ep))
    end
end

function setepboughtcount(gmlevel, rolename, ep)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:SetEPBoughtCount(tonumber(ep))
    end
end

function setitemboughtcount(gmlevel, rolename, tid, count)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:SetItemBoughtCount(tonumber(tid), tonumber(count))
    end
end

function finishdayquest(gmlevel, rolename, questtypeid, fihishcount)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:FinishDayQuest(tonumber(questtypeid), tonumber(fihishcount))
    end
end

function addpet(gmlevel, rolename, tid)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddPet(tonumber(tid))
    end
end

function setlevelpass(gmlevel, rolename, level)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:SetLevelPass(tonumber(level))
    end
end

function addskillpoint(gmlevel, rolename, val)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddSkillPoint(tonumber(val))
    end
end

function adddrop(gmlevel, rolename, dropid)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddDrop(tonumber(dropid))
    end
end

function sendmail(gmlevel, rolename, tid, count)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:SendMail(tonumber(tid), tonumber(count))
    end
end

function addap(gmlevel, rolename, ap)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddAP(tonumber(ap))
    end
end

function costap(gmlevel, rolename, ap)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:CostAP(tonumber(ap))
    end
end

function addpvptimes(gmlevel, rolename, ntime)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddPVPTimes(tonumber(ntime))
    end
end

function addrepute(gmlevel, rolename, nrepute)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddRepute(tonumber(nrepute))
    end
end

function addpvppoints(gmlevel, rolename, npoints)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddPVPPoints(tonumber(npoints))
    end
end

function costpvptimes(gmlevel, rolename, ntime)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:CostPVPTimes(tonumber(ntime))
    end
end

function kickout(gmlevel, rolename)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    KickOutRole(rolename)
end

function addbattlestar(gmlevel, rolename, battleid, count)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:AddBattleStar(tonumber(battleid), tonumber(count))
    end
end

function opentest(gmlevel, rolename)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:SetLevelPass(11021)
        role:SetLevelPass(11022)
        role:SetLevelPass(11023)
        role:SetLevelPass(11031)
        role:SetLevelPass(11032)
        role:SetLevelPass(11033)
        role:SetLevelPass(11041)
        role:SetLevelPass(11042)
        role:SetLevelPass(11043)
        role:SetLevelPass(11051)
        role:SetLevelPass(11052)
        role:SetLevelPass(11053)
        role:SetLevelPass(11061)
        role:SetLevelPass(11062)
        role:SetLevelPass(11063)
        role:SetLevelPass(12011)
        role:SetLevelPass(12012)
        role:SetLevelPass(12013)
        role:SetLevelPass(12021)
        role:SetLevelPass(12022)
        role:SetLevelPass(12023)
        role:SetLevelPass(12031)
        role:SetLevelPass(12032)
        role:SetLevelPass(12033)
        role:SetLevelPass(12041)
        role:SetLevelPass(12042)
        role:SetLevelPass(12043)
        role:SetLevelPass(12051)
        role:SetLevelPass(12052)
        role:SetLevelPass(12053)
        role:SetLevelPass(12061)
        role:SetLevelPass(12062)
        role:SetLevelPass(12063)
        role:SetLevelPass(13011)
        role:SetLevelPass(13012)
        role:SetLevelPass(13013)
        role:SetLevelPass(13021)
        role:SetLevelPass(13022)
        role:SetLevelPass(13023)
        role:SetLevelPass(13031)
        role:SetLevelPass(13032)
        role:SetLevelPass(13033)
        role:SetLevelPass(13041)
        role:SetLevelPass(13042)
        role:SetLevelPass(13043)
        role:SetLevelPass(13051)
        role:SetLevelPass(13052)
        role:SetLevelPass(13053)
        role:SetLevelPass(13061)
        role:SetLevelPass(13062)
        role:SetLevelPass(13063)
        role:SetLevelPass(14011)
        role:SetLevelPass(14012)
        role:SetLevelPass(14013)
        role:SetLevelPass(14021)
        role:SetLevelPass(14022)
        role:SetLevelPass(14023)
        role:SetLevelPass(14031)
        role:SetLevelPass(14032)
        role:SetLevelPass(14033)
        role:SetLevelPass(14041)
        role:SetLevelPass(14042)
        role:SetLevelPass(14043)
        role:SetLevelPass(14051)
        role:SetLevelPass(14052)
        role:SetLevelPass(14053)
        role:SetLevelPass(14061)
        role:SetLevelPass(14062)
        role:SetLevelPass(14063)
        role:SetLevelPass(21011)
        role:SetLevelPass(21012)
        role:SetLevelPass(21013)
        role:SetLevelPass(21021)
        role:SetLevelPass(21022)
        role:SetLevelPass(21023)
        role:SetLevelPass(21031)
        role:SetLevelPass(21032)
        role:SetLevelPass(21033)
        role:SetLevelPass(21041)
        role:SetLevelPass(21042)
        role:SetLevelPass(21043)
        role:SetLevelPass(21051)
        role:SetLevelPass(21052)
        role:SetLevelPass(21053)
        role:SetLevelPass(21061)
        role:SetLevelPass(21062)
        role:SetLevelPass(21063)
        role:SetLevelPass(22011)
        role:SetLevelPass(22012)
        role:SetLevelPass(22013)
        role:SetLevelPass(22021)
        role:SetLevelPass(22022)
        role:SetLevelPass(22023)
        role:SetLevelPass(22031)
        role:SetLevelPass(22032)
        role:SetLevelPass(22033)
        role:SetLevelPass(22041)
        role:SetLevelPass(22042)
        role:SetLevelPass(22043)
        role:SetLevelPass(22051)
        role:SetLevelPass(22052)
        role:SetLevelPass(22053)
        role:SetLevelPass(22061)
        role:SetLevelPass(22062)
        role:SetLevelPass(22063)
        role:SetLevelPass(23011)
        role:SetLevelPass(23012)
        role:SetLevelPass(23013)
        role:SetLevelPass(23021)
        role:SetLevelPass(23022)
        role:SetLevelPass(23023)
        role:SetLevelPass(23031)
        role:SetLevelPass(23032)
        role:SetLevelPass(23033)
        role:SetLevelPass(23041)
        role:SetLevelPass(23042)
        role:SetLevelPass(23043)
        role:SetLevelPass(23051)
        role:SetLevelPass(23052)
        role:SetLevelPass(23053)
        role:SetLevelPass(23061)
        role:SetLevelPass(23062)
        role:SetLevelPass(23063)
        role:SetLevelPass(24011)
        role:SetLevelPass(24012)
        role:SetLevelPass(24013)
        role:SetLevelPass(24021)
        role:SetLevelPass(24022)
        role:SetLevelPass(24023)
        role:SetLevelPass(24031)
        role:SetLevelPass(24032)
        role:SetLevelPass(24033)
        role:SetLevelPass(24041)
        role:SetLevelPass(24042)
        role:SetLevelPass(24043)
        role:SetLevelPass(24051)
        role:SetLevelPass(24052)
        role:SetLevelPass(24053)
        role:SetLevelPass(24061)
        role:SetLevelPass(24062)
        role:SetLevelPass(24063)
    end
end

function pay(gmlevel, rolename, productid)
    local glevel = tonumber(gmlevel)
    if glevel < 1 then
        return
    end
    local role = FindRoleByName(rolename)
    if role ~= nil then
        role:GMPay(tonumber(productid))
    end
end

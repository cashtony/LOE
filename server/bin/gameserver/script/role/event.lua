-- lua script
module (..., package.seeall)

function FirstEnterGame(role, res)
    if 1 == role:GetJob() then
        FirstEnterGameByJob1(role, res)
    elseif 4 == role:GetJob() then
        FirstEnterGameByJob4(role, res)
    elseif 7 == role:GetJob() then
        FirstEnterGameByJob7(role, res)
    elseif 10 == role:GetJob() then
        FirstEnterGameByJob10(role, res)
    end

    FirstEnterGameByCommon(role, res)
    res.value = 0
end

-- 公共部位
function FirstEnterGameByCommon(role, res)

    role:AddCash(100000, true)
    role:AddMoney(100000)

end

-- 职业1
function FirstEnterGameByJob1(role, res)
    role:AddItemAndEquip(1000)
    role:AddItemAndEquip(1001)
    role:AddItemAndEquip(1002)
    role:AddItemAndEquip(1003)
    role:AddItemAndEquip(1004)
    role:AddItemAndEquip(1005)
    role:AddItemAndEquip(1006)
    role:AddItemAndEquip(1007)
    role:AddItemAndEquip(1008)
    role:AddItemAndEquip(1009)
end

-- 职业1
function FirstEnterGameByJob4(role, res)
    role:AddItemAndEquip(4000)
    role:AddItemAndEquip(4001)
    role:AddItemAndEquip(4002)
    role:AddItemAndEquip(4003)
    role:AddItemAndEquip(4004)
    role:AddItemAndEquip(4005)
    role:AddItemAndEquip(4006)
    role:AddItemAndEquip(4007)
    role:AddItemAndEquip(4008)
    role:AddItemAndEquip(4009)
end

-- 职业1
function FirstEnterGameByJob7(role, res)
    role:AddItemAndEquip(8000)
    role:AddItemAndEquip(8001)
    role:AddItemAndEquip(8002)
    role:AddItemAndEquip(8003)
    role:AddItemAndEquip(8004)
    role:AddItemAndEquip(8005)
    role:AddItemAndEquip(8006)
    role:AddItemAndEquip(8007)
    role:AddItemAndEquip(8008)
    role:AddItemAndEquip(8009)

end

-- 职业1
function FirstEnterGameByJob10(role, res)
    role:AddItemAndEquip(6000)
    role:AddItemAndEquip(6001)
    role:AddItemAndEquip(6002)
    role:AddItemAndEquip(6003)
    role:AddItemAndEquip(6004)
    role:AddItemAndEquip(6005)
    role:AddItemAndEquip(6006)
    role:AddItemAndEquip(6007)
    role:AddItemAndEquip(6008)
    role:AddItemAndEquip(6009)

end

function EnterGame(role, res)
    -- role:AddExp(1000)
end

function EventRoleLevelUp(role, level, res)
    if level == 2 then
        role:AddVipEP(5)
    elseif level == 3 then
        role:AddVipEP(5)
    elseif level == 4 then
        role:AddVipEP(5)
    elseif level == 5 then
        role:AddVipEP(5)
    elseif level == 6 then
        role:AddVipEP(5)
    elseif level == 7 then
        role:AddVipEP(5)
    elseif level == 3 then
        role:AddVipEP(5)
    elseif level == 8 then
        role:AddVipEP(5)
    elseif level == 9 then
        role:AddVipEP(5)
    elseif level == 3 then
        role:AddVipEP(5)
    elseif level == 10 then
        role:AddVipEP(5)
    elseif level == 11 then
        role:AddVipEP(5)
    elseif level == 12 then
        role:AddVipEP(5)
    elseif level == 13 then
        role:AddVipEP(5)
    elseif level == 14 then
        role:AddVipEP(5)
    elseif level == 15 then
        role:AddVipEP(5)
    elseif level == 16 then
        role:AddVipEP(5)
    elseif level == 17 then
        role:AddVipEP(5)
    elseif level == 18 then
        role:AddVipEP(5)
    elseif level == 19 then
        role:AddVipEP(5)
    elseif level == 20 then
        role:AddVipEP(5)
    elseif level == 21 then
        role:AddVipEP(5)
    elseif level == 22 then
        role:AddVipEP(5)
    elseif level == 23 then
        role:AddVipEP(5)
    elseif level == 3 then
        role:AddVipEP(5)
    elseif level == 24 then
        role:AddVipEP(5)
    elseif level == 25 then
        role:AddVipEP(5)
    elseif level == 26 then
        role:AddVipEP(5)
    elseif level == 27 then
        role:AddVipEP(5)
    elseif level == 28 then
        role:AddVipEP(5)
    elseif level == 29 then
        role:AddVipEP(5)
    elseif level == 30 then
        role:AddVipEP(5)
    elseif level == 31 then
        role:AddVipEP(5)
    elseif level == 32 then
        role:AddVipEP(5)
    elseif level == 33 then
        role:AddVipEP(5)
    elseif level == 34 then
        role:AddVipEP(5)
    elseif level == 35 then
        role:AddVipEP(5)
    elseif level == 36 then
        role:AddVipEP(5)
    elseif level == 37 then
        role:AddVipEP(5)
    elseif level == 38 then
        role:AddVipEP(5)
    elseif level == 39 then
        role:AddVipEP(5)
    elseif level == 40 then
        role:AddVipEP(5)
    elseif level == 41 then
        role:AddVipEP(5)
    elseif level == 42 then
        role:AddVipEP(5)
    elseif level == 43 then
        role:AddVipEP(5)
    elseif level == 44 then
        role:AddVipEP(5)
    elseif level == 45 then
        role:AddVipEP(5)
    elseif level == 46 then
        role:AddVipEP(5)
    elseif level == 47 then
        role:AddVipEP(5)
    elseif level == 48 then
        role:AddVipEP(5)
    elseif level == 49 then
        role:AddVipEP(5)
    elseif level == 50 then
        role:AddVipEP(5)
    elseif level == 51 then
        role:AddVipEP(5)
    elseif level == 52 then
        role:AddVipEP(5)
    elseif level == 53 then
        role:AddVipEP(5)
    elseif level == 54 then
        role:AddVipEP(5)
    elseif level == 55 then
        role:AddVipEP(5)
    elseif level == 56 then
        role:AddVipEP(5)
    elseif level == 57 then
        role:AddVipEP(5)
    elseif level == 58 then
        role:AddVipEP(5)
    elseif level == 59 then
        role:AddVipEP(5)
    elseif level == 60 then
        role:AddVipEP(5)
    else
        role:AddVipEP(5)
    end
end


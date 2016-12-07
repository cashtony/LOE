-- lua script
module (..., package.seeall)

function EventSell(role, item, res)
    local count = item:GetCount()

    role:AddMoney(item:GetValue() * item:GetCount())

    item:ReduceCount(count)
    res.value = 0
end

function EventAddPet(role, item, res)
    local count = 0
    for i=1,item:GetCount(),1 do
        if not role:AddPet(item:GetExpend()) then
            item:ReduceCount(count)
            res.value = 0
            return
        end
        count = count + 1
    end

    item:ReduceCount(count)
    res.value = 0
end

function EventAddVipEP(role, item, res)
    local count = item:GetCount()

    role:AddVipEP(item:GetExpend() * item:GetCount())

    item:ReduceCount(count)
    res.value = 0
end

function EventAddMoney(role, item, res)
    local count = item:GetCount()

    role:AddMoney(item:GetExpend() * item:GetCount())

    item:ReduceCount(count)
    res.value = 0
end

function EventAddCash(role, item, res)
    local count = item:GetCount()

    role:AddCash(item:GetExpend() * item:GetCount(), false)

    item:ReduceCount(count)
    res.value = 0
end

function EventAddNonCash(role, item, res)
    local count = item:GetCount()

    role:AddCash(item:GetExpend() * item:GetCount(), true)

    item:ReduceCount(count)
    res.value = 0
end

function EventAddExp(role, item, res)
    local count = item:GetCount()

    role:AddExp(item:GetExpend() * item:GetCount())

    item:ReduceCount(count)
    res.value = 0
end

function EventGatherAddItem(role, item, res)
    local count = item:GetCount()

    role:GatherAddItem(item:GetTID(), item:GetCount())

    item:ReduceCount(count)
    res.value = 0
end

function EventAddDrop(role, item, res)
    local count = item:GetCount()

    for i=1,item:GetCount(),1 do
        role:AddDrop(item:GetDropID())
    end
    item:ReduceCount(count)
    res.value = 0;
end


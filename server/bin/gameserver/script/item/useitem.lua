-- lua script
module (..., package.seeall)

function EventAddDrop(role, item, res)
    role:AddDrop(item:GetDropID())
    role:ReduceItem(item,1)
    res.value = 0;
end

function EventAddItem(role, item, res)
    role:AddItem(item:GetGenItemID(), item:GetGenItemCount())
    role:ReduceItem(item,1)
    res.value = 0;
end

function EventAddExpAll(role, item, res)
    local count = item:GetCount()

    role:AddExp(item:GetExpend() * item:GetCount())

    role:ReduceItem(item,count)
    res.value = 0
end

function EventAddExp(role, item, res)

    role:AddExp(item:GetExpend())

    role:ReduceItem(item,1)
    res.value = 0
end

-- lua script
module (..., package.seeall)

function merge5(role, pet1, pet2, res)
    res.value = -1

    if (pet1:GetTemplateID() == 10001 and pet2:GetTemplateID() == 10004)
        or (pet1:GetTemplateID() == 10004 and pet2:GetTemplateID() == 10001) then

        if (role:AddPet(101)) then
            role:ErasePet(pet1)
            role:ErasePet(pet2)
            res.value = 0
            return
        end
    end
end

function EventSell(role, pet, res)
    role:OnDebug("测试宠物出售获得神秘水晶")
    if (pet:GetAbility() == 3) then
        role:AddItem(102, math.ldexp(1,pet:GetUp()) * pet:GetCrystal())  
    elseif (pet:GetAbility() == 4) then
        role:AddItem(102, math.ldexp(1,pet:GetUp()) * pet:GetCrystal())  
    end

    role:AddMoney(pet:GetSellMoney())

    res.value = 0
end

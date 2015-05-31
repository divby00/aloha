Test = {}
Test.__index = Test

function Test:new(x, y)
    return setmetatable({x = x, y = y}, Test)
end

function Test:suma()
    return self.x + self.y
end

function Test:resta()
    --local f = function () error({code=121}) end
    local f = function ()
        self.x = 111
        if self.x == 111 then
            error({codigo=-1})
        end
    end
    local status, err = pcall(f)
end

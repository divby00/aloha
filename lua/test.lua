Test = {}
Test.__index = Test

function Test:new(x, y)
    return setmetatable({x = x, y = y}, Test)
end

function Test:suma()
    return self.x + self.y
end

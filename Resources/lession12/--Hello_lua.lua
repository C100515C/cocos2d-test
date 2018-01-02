--Hello_lua.lua
function cc.disable_global()
setmetatable(__g, {
__newindex = function(_, name, value)
error(string.format("USE \" cc.exports.%s = value \" INSTEAD OF SET GLOBAL VARIABLE", name), 0)
end
})
end

if CC_DISABLE_GLOBAL then
cc.disable_global()
end<span style="font-family:Arial;font-size:18px;color:#333333;"><span style="line-height: 26px;">
</span></span>

myName = "beautiful girl";

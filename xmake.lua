set_project("AlgoTrick")

add_rules("mode.debug", "mode.release")

function AddTarget(target_name, dot_output)
    target(target_name)
        set_languages("cxx23")
        set_kind("binary")
        set_warnings("all", "error")

        add_includedirs("src")
        add_files("src/" .. target_name .. ".cpp")
        add_files("src/Utils/**.cpp")

        after_build(function (target)
            os.cp(target:targetfile(), "bin/")
            if dot_output then
                if is_plat("windows") then
                    os.exec("cmd /c \"" .. target:targetfile() .. " > bin/" .. target_name .. "_output.dot\"")
                elseif is_plat("linux") then
                    os.exec("sh -c \"" .. target:targetfile() .. " > bin/" .. target_name .. "_output.dot\"")
                end
            end       
        end)
    target_end()
end

AddTarget("IndexSort")
AddTarget("BinaryEnumerationPlus")
AddTarget("Factors")
AddTarget("Grouping")

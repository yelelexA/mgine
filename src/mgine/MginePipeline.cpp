#include "mgine/MginePipeline.h"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace mgine
{
    MginePipeline::MginePipeline(const std::string& vertFilepath, const std::string& fragFilepath)
    {
        CreatePipeline(vertFilepath, fragFilepath);
    }

    std::vector<char> MginePipeline::ReadFile(const std::string& filepath)
    {
        std::ifstream file{filepath, std::ios::ate | std::ios::binary};

        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + filepath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void MginePipeline::CreatePipeline(const std::string& vertFilePath, const std::string& fragFilePath)
    {
        auto vertCode = ReadFile(vertFilePath);
        auto fragCode = ReadFile(fragFilePath);

        std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
        std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }
}
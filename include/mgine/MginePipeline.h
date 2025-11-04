#pragma once

#include <string>
#include <vector>

namespace mgine
{
    class MginePipeline
    {
        public:
            MginePipeline(const std::string& vertFilepath, const std::string& fragFilepath);

        private:
            static std::vector<char> ReadFile(const std::string& filepath);

            void CreatePipeline(const std::string& vertFilepath, const std::string& fragFilepath);
    };
}
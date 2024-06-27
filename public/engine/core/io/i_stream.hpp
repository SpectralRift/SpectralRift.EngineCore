#pragma once

#include <vector>
#include <memory>

namespace engine::core::io {
    struct IStream {
        virtual ~IStream() = default;

        virtual bool open(bool writeAccess) = 0;

        virtual void close() = 0;

        virtual bool isOpen() = 0;

        virtual std::vector<uint8_t> read(int count) = 0;

        virtual int write(const std::vector<uint8_t> &data) = 0;

        virtual void seek(int position) = 0;

        virtual int getPosition() = 0;

        virtual int getSize() = 0;
    };
}
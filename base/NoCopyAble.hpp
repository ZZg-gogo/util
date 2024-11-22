#pragma once

namespace ZZG
{

class NoCopyAble
{

public:
    NoCopyAble() = default;
    ~NoCopyAble()= default;

    NoCopyAble(const NoCopyAble& ) = delete;
    NoCopyAble& operator=(const NoCopyAble& ) = delete;

};






}
#pragma once
#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "CCharacter.h"
class CXPlayer : public CXCharacter
{
public:
	void Update() override;
};
#endif
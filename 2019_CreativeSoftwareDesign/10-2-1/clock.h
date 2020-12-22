#pragma once
#include"clock_time.h"

class Clock {
protected:
	ClockTime _clockTime;
	double _driftPerSecond;
	double _totalDrift;

public:
	Clock(int hour, int minute, int second, double driftPerSecond);
	virtual ~Clock() {};
	void reset();
	void tick();
	virtual void displayTime() = 0;
};

class NaturalClock :public Clock {
public:
	NaturalClock(int hour, int minute, int second, double driftPerSecond);
	virtual ~NaturalClock() {};
};
class MechanicalClock :public Clock {
public:
	MechanicalClock(int hour, int minute, int second, double driftPerSecond);
	virtual ~MechanicalClock() {};
};
class DigitalClock :public Clock {
public:
	DigitalClock(int hour, int minute, int second, double driftPerSecond);
	virtual ~DigitalClock() {};
};
class QuantomClock :public Clock {
public:
	QuantomClock(int hour, int minute, int second, double driftPerSecond);
	virtual ~QuantomClock() {};
};

class SundialClock :public NaturalClock {
public:
	SundialClock(int hour, int minutes, int second);
	virtual ~SundialClock() {};
	virtual void displayTime();
};
class CuckooClock :public MechanicalClock {
public:
	CuckooClock(int hour, int minutes, int second);
	virtual ~CuckooClock() {};
	virtual void displayTime();
};
class GrandFatherClock :public MechanicalClock {
public:
	GrandFatherClock(int hour, int minutes, int second);
	virtual ~GrandFatherClock() {};
	virtual void displayTime();
};
class WristClock :public DigitalClock {
public:
	WristClock(int hour, int minutes, int second);
	virtual ~WristClock() {};
	virtual void displayTime();
};
class AtomicClock :public QuantomClock {
public:
	AtomicClock(int hour, int minutes, int second);
	virtual ~AtomicClock() {};
	virtual void displayTime();
};







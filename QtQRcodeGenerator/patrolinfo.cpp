#include "patrolinfo.h"

PatrolInfo::PatrolInfo()
{

}

PatrolInfo::~PatrolInfo()
{

}

QString PatrolInfo::patrolName() const
{
	return m_patrolName;
}

void PatrolInfo::setPatrolName(const QString &name)
{
	m_patrolName = name;
}

QString PatrolInfo::areaName() const
{
	return m_areaName;
}

void PatrolInfo::setAreaName(const QString &areaName)
{
	m_areaName = areaName;
}

QString PatrolInfo::peopleInCharge() const
{
	return m_peopleInCharge;
}

void PatrolInfo::setPeopleInCharege(const QString &peopleInCharge)
{
	m_peopleInCharge = peopleInCharge;
}

QString PatrolInfo::period() const
{
	return m_period;
}

void PatrolInfo::setPeriod(const QString &period)
{
	m_period = period;
}

QString PatrolInfo::weekDays() const
{
	return m_weekDays;
}

void PatrolInfo::setWeekDays(const QString &weekDays)
{
	m_weekDays = weekDays;
}

QString PatrolInfo::startTime() const
{
	return m_startTime;
}

void PatrolInfo::setStartTime(const QString &startTime)
{
	m_startTime = startTime;
}

QString PatrolInfo::endTime() const
{
	return m_endTime;
}

void PatrolInfo::setEndTime(const QString &endTime)
{
	m_endTime = endTime;
}

QString PatrolInfo::endDay() const
{
	return m_endDay;
}

void PatrolInfo::setEndDay(const QString &endDay)
{
	m_endDay = endDay;
}

QString PatrolInfo::patrolTimesPerDay() const
{
	return m_patrolTimesPerDay;
}

void PatrolInfo::setPatrolTimesPerDay(const QString &patrolTimesPerDady)
{
	m_patrolTimesPerDay = patrolTimesPerDady;
}

QString PatrolInfo::patrolTarget() const
{
	return m_patrolTarget;
}

void PatrolInfo::setPatrolTarget(const QString patrolTarget)
{
	m_patrolTarget = patrolTarget;
}

#ifndef PATROLINFO_H
#define PATROLINFO_H

#include <QString>

class PatrolInfo
{
public:
	PatrolInfo();
	~PatrolInfo();

	QString patrolName() const;
	void setPatrolName(const QString &name);

	QString areaName() const;
	void setAreaName(const QString &areaName);

	QString peopleInCharge() const;
	void setPeopleInCharege(const QString &peopleInCharge);

	QString period() const;
	void setPeriod(const QString &period);

	QString weekDays() const;
	void setWeekDays(const QString &weekDays);

	QString startTime() const;
	void setStartTime(const QString &startTime);

	QString endTime() const;
	void setEndTime(const QString &endTime);

	QString endDay() const;
	void setEndDay(const QString &endDay);

	QString patrolTimesPerDay() const;
	void setPatrolTimesPerDay(const QString &patrolTimesPerDady);

	QString patrolTarget() const;
	void setPatrolTarget(const QString patrolTarget);
private:
	QString m_patrolName;
	QString m_areaName;
	QString m_peopleInCharge;
	QString m_period;
	QString m_weekDays;
	QString m_startTime;
	QString m_endTime;
	QString m_endDay;
	QString m_patrolTimesPerDay;
	QString m_patrolTarget;
};

#endif // PATROLINFO_H

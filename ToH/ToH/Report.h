#pragma once
#include <iostream>
#include <map>
#include <string>
#include "IObserver.h"

#define REPORT PlayReport::GetInstance()

using namespace std;

class PlayReport : public IObserver
{
private:
    static PlayReport* Instance;

    // �̱��� ������
    PlayReport() = default;

public:
    static PlayReport* GetInstance()
    {
        if (Instance == nullptr)
        {
            Instance = new PlayReport();
        }
        return Instance;
    }


private:

    // ���� ���
    map<string, int> SpawnMonsterCount;
    map<string, int> KillMonsterCount;

    // ������ ���
    map<string, int> UsedItems;
    map<string, int> AcquiredItems;

    // ȸ�� ������ ��� �� ȸ���� �ѷ�
    map<string, int> RecoveredCount;
    int TotalRecoveredHealth = 0;
    int TotalRecoveredMana = 0;

    // ��� ���
    int TotalGoldEarned = 0;
    int TotalGoldSpent = 0;

    // ���� ���
    map<string, int> AttackCountByType;
    int BasicAttackCount = 0;
    int TotalSkillAttackDamage = 0;
    int TotalBasicAttackDamage = 0;
    int TotalDamageDealt = 0;

    // ���� �Լ�
    void PrintMap(const string& title, const map<string, int>& data) const;

public:

    // ��� ���� �Լ�
    void OnMonsterEvent(const string& monsterName, const string& eventType) override;
    void OnItemEvent(const string& itemName, const string& eventType, int recoveredHealth = 0, int recoveredMana = 0) override;
    void OnBattleEvent(const string& skillName, const string& eventType, int damage) override;
    void OnGoldEvent(const string& eventType, int gold) override;


    // ��� ���� �Լ�
    void GenerateMonsterReport() const;
    void GenerateItemReport() const;
    void GenerateBattleReport() const;
    void GenerateGoldReport() const;

    
    int CurrentGold() const;


    // ��ü ������ ���
    void GenerateReport() const;

};
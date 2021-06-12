#ifndef QUWICLIENT_H
#define QUWICLIENT_H

#include <QString>
#include <QtNetwork>
#include <QErrorMessage>
#include <QList>
#include <QUuid>

class User{

public:

    qint32 id;
    qint32 id_company;
    QString role;
    QString name;
    QString avatar_url;
    qint8 is_online;
    QString dta_activity;
    qint8 is_timer_online;
    User() = default;

};

class Project{

public:

    qint32 id;
    QString name;
    QString uid;
    QString logo_url;
    QByteArray logo;
    qint32 position;
    qint32 is_active;
    qint32 is_owner_watcher;
    QList<User> users;

    qint32 spent_time_week;
    qint32 spent_time_month;
    qint32 spent_time_all;

    Project() = default;

};

class Entity
{
public:

    Entity(QString server = "https://api.quwi.com/v2/");

    ~Entity();

    bool auth(QString login, QString password);

    bool logout();

private:

    QList<User> parseUsers(QJsonArray jsonObjUsers);

    Project parseProject(QJsonObject jsonObjProject);

public:
    QMap<qint32, Project> getProjects();
    Project getProject(qint32 id);
    Project upgradeProject(Project project);

    QByteArray load(QString url);

private:

    QString host;
    QNetworkAccessManager *manager;

    QString token;

};

#endif // QUWICLIENT_H

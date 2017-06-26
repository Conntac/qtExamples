#ifndef TRANSLATIONMANAGER_H
#define TRANSLATIONMANAGER_H

#include <QObject>
#include <QTranslator>
#include <QGuiApplication>

class TranslationManager : public QObject
{
    Q_OBJECT

public:
    explicit TranslationManager(QObject *parent = nullptr);
    ~TranslationManager();
    QTranslator* translator(QString lang);

signals:
    void translatorChanged();

public slots:
    void changeTranslator(QString lang);

private:
    QTranslator* m_frTranslator;
    QTranslator* m_deTranslator;
};

#endif // TRANSLATIONMANAGER_H

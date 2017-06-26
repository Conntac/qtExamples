#include "translationmanager.h"
#include <QLocale>
#include <QDebug>

TranslationManager::TranslationManager(QObject *parent) : QObject(parent),
    m_frTranslator(new QTranslator()), m_deTranslator(new QTranslator())
{
    m_deTranslator->load(":/translations/translation_de");
    m_frTranslator->load(":/translations/translation_fr");
}

TranslationManager::~TranslationManager() {
    delete m_deTranslator;
    delete m_frTranslator;
}

void TranslationManager::changeTranslator(QString lang) {
    if(lang == "de") {
        qApp->removeTranslator(m_frTranslator);
        qApp->installTranslator(m_deTranslator);
    } else if( lang == "fr") {
        qApp->removeTranslator(m_deTranslator);
        qApp->installTranslator(m_frTranslator);
    }

    emit translatorChanged();
}

QTranslator *TranslationManager::translator(QString lang) {
    if(lang == "de") {
        return m_deTranslator;
    } else if (lang == "fr") {
        return m_frTranslator;
    } else {
        return nullptr;
    }
}





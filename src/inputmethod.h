/*
    KWin - the KDE window manager
    This file is part of the KDE project.

    SPDX-FileCopyrightText: 2016 Martin Gräßlin <mgraesslin@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/
#ifndef KWIN_VIRTUAL_KEYBOARD_H
#define KWIN_VIRTUAL_KEYBOARD_H

#include <QObject>

#include <kwinglobals.h>
#include <kwin_export.h>

#include <abstract_client.h>
#include <KWaylandServer/textinput_v2_interface.h>

class KStatusNotifierItem;

namespace KWin
{

/**
 * This class implements the zwp_input_method_unstable_v1, which is currently used to provide
 * the Virtual Keyboard using supported input method client (maliit-keyboard e.g.)
 **/
class KWIN_EXPORT InputMethod : public QObject
{
    Q_OBJECT
public:
    ~InputMethod() override;

    void init();
    void hide();
    void show();

Q_SIGNALS:
    void visibleChanged(bool shown);
    void enabledChanged(bool enabled);

private Q_SLOTS:
    void clientAdded(AbstractClient* client);

    // textinput interface slots
    void handleFocusedSurfaceChanged();
    void surroundingTextChanged();
    void contentTypeChanged();
    void textInputInterfaceV2EnabledChanged();
    void textInputInterfaceV3EnabledChanged();
    void stateCommitted(uint32_t serial);
    void textInputInterfaceV2StateUpdated(quint32 serial, KWaylandServer::TextInputV2Interface::UpdateReason reason);

    // inputcontext slots
    void setPreeditString(uint32_t serial, const QString &text, const QString &commit);
    void setPreeditCursor(qint32 index);

private:
    void setVisible(bool shown);
    void setEnabled(bool enable);
    void updateSni();
    void updateInputPanelState();
    void adoptInputMethodContext();

    struct {
        QString text = QString();
        quint32 begin = 0;
        quint32 end = 0;
    } preedit;

    bool m_enabled = false;
    bool m_visible = false;
    KStatusNotifierItem *m_sni = nullptr;
    QPointer<AbstractClient> m_inputClient;
    QPointer<AbstractClient> m_trackedClient;

    KWIN_SINGLETON(InputMethod)
};

}

#endif

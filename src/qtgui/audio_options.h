/* -*- c++ -*- */
/*
 * Gqrx SDR: Software defined radio receiver powered by GNU Radio and Qt
 *           http://gqrx.dk/
 *
 * Copyright 2013 Alexandru Csete OZ9AEC.
 *
 * Gqrx is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * Gqrx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Gqrx; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef AUDIO_OPTIONS_H
#define AUDIO_OPTIONS_H

#include <QCloseEvent>
#include <QDialog>
#include <QDir>
#include <QPalette>

namespace Ui {
    class CAudioOptions;
}

/*! \brief GUI widget for configuring audio options. */
class CAudioOptions : public QDialog
{
    Q_OBJECT
    
public:
    explicit CAudioOptions(QWidget *parent = 0);
    ~CAudioOptions();

    void closeEvent(QCloseEvent *event);

    void setRecDir(const QString &dir);
    void setUdpHost(const QString &host);
    void setUdpPort(int port);

    void setFftSplit(int pct_2d);
    int  getFftSplit(void) const;

    void setFftMin(int min_db);
    int  getFftMin(void) const;

signals:
    void newFftSplit(int pct_2d);
    void newFftMin(int min_db);

    /*! \brief Signal emitted when a new valid directory has been selected. */
    void newRecDirSelected(const QString &dir);

    void newUdpHost(const QString text);
    void newUdpPort(int port);

private slots:
    void on_splitSpinBox_valueChanged(int value);
    void on_scaleSpinBox_valueChanged(int value);
    void on_recDirEdit_textChanged(const QString &text);
    void on_recDirButton_clicked();
    void on_udpHost_textChanged(const QString &text);
    void on_udpPort_valueChanged(int port);

private:
    Ui::CAudioOptions *ui;            /*!< The user interface widget. */
    QDir              *work_dir;      /*!< Used for validating chosen directory. */
    QPalette          *error_palette; /*!< Palette used to indicate an error. */
};

#endif // AUDIO_OPTIONS_H

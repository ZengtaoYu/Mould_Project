#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QScroller>

class SpareTableViewModel;
class LinkableItemDelegate;
class LinkableTableView;

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

signals:
    void mysignal();

private slots:
    void doLinkActivated(QString link);

private:
    QString extractSpareIdFromLink(const QString &link) const;

    LinkableTableView *m_linkableTableView;
    SpareTableViewModel *m_spareTableViewModel;
    LinkableItemDelegate *m_linkableItemDelegate;

    QString m_moldId;
};

#endif // MAINWIDGET_H

#ifndef LINKABLEVIEW_H
#define LINKABLEVIEW_H

#include <QTableView>

class LinkableTableView : public QTableView {
    Q_OBJECT

public:
    explicit LinkableTableView(QWidget *parent = nullptr);

signals:
    void linkActivated(QString link);
    void linkHovered(QString link);
    void linkUnhovered();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QString anchorAt(const QPoint &pos) const;

    QString m_mousePressAnchor;
    QString m_lastHoveredAnchor;
};

#endif // LINKABLEVIEW_H

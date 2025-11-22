#ifndef LINKABLEITEMDELEGATE_H
#define LINKABLEITEMDELEGATE_H

#include <QStyledItemDelegate>

class LinkableItemDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    explicit LinkableItemDelegate(QObject *parent = nullptr);

    QString anchorAt(const QString &html, const QPoint &point) const;

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // LINKABLEITEMDELEGATE_H

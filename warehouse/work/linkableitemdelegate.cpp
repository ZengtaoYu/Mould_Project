#include "linkableitemdelegate.h"

#include <QPainter>
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>
#include <QIcon>
#include <QSize>

LinkableItemDelegate::LinkableItemDelegate(QObject *parent) : QStyledItemDelegate(parent) {
}

QString LinkableItemDelegate::anchorAt(const QString &html, const QPoint &point) const {
    QTextDocument doc;
    doc.setHtml(html);
    auto textLayout = doc.documentLayout();
    Q_ASSERT(textLayout != nullptr);
    return textLayout->anchorAt(point);
}

void LinkableItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
    const QModelIndex &index) const {
    QStyleOptionViewItem options = option;
    initStyleOption(&options, index);
    painter->save();
    QTextDocument doc;
    doc.setHtml(options.text);
    options.text = "";
    options.widget->style()->drawControl(QStyle::CE_ItemViewItem, &options, painter);
    QSize iconSize = options.icon.actualSize(options.rect.size());
    // right shift the icon
    painter->translate(options.rect.left() + iconSize.width(), options.rect.top());
    QRect clip(0, 0, options.rect.width() + iconSize.width(), options.rect.height());
    painter->setClipRect(clip);
    QAbstractTextDocumentLayout::PaintContext ctx;
    // Adjust color palette if the cell is selected
    if(option.state & QStyle::State_Selected) {
        ctx.palette.setColor(QPalette::Text, option.palette.color(QPalette::Active, QPalette::HighlightedText));
    }
    ctx.clip = clip;
    // Vertical Center alignment instead of the default top alignment
    painter->translate(0, 0.1 * (options.rect.height() - doc.size().height()));
    doc.documentLayout()->draw(painter, ctx);
    painter->restore();
}

QSize LinkableItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyleOptionViewItem options = option;
    initStyleOption(&options, index);
    QTextDocument doc;
    doc.setHtml(options.text);
    doc.setTextWidth(options.rect.width());
    return QSize(doc.idealWidth(), doc.size().height());
}

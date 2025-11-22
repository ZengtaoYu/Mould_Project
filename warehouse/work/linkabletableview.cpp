#include "linkabletableview.h"
#include "linkableitemdelegate.h"

#include <QApplication>
#include <QCursor>
#include <QMouseEvent>

LinkableTableView::LinkableTableView(QWidget *parent) : QTableView(parent) {
    setMouseTracking(true);
}

void LinkableTableView::mousePressEvent(QMouseEvent *event) {
    QTableView::mousePressEvent(event);
    auto anchor = anchorAt(event->pos());
    m_mousePressAnchor = anchor;
}

void LinkableTableView::mouseMoveEvent(QMouseEvent *event) {
    auto anchor = anchorAt(event->pos());
    if(m_mousePressAnchor != anchor) {
        m_mousePressAnchor.clear();
    }
    if(m_lastHoveredAnchor != anchor) {
        m_lastHoveredAnchor = anchor;
        if(!m_lastHoveredAnchor.isEmpty()) {
            QApplication::setOverrideCursor(QCursor(Qt::PointingHandCursor));
            emit linkHovered(m_lastHoveredAnchor);
        } else {
            QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
            emit linkUnhovered();
        }
    }
}

void LinkableTableView::mouseReleaseEvent(QMouseEvent *event) {
    if(!m_mousePressAnchor.isEmpty()) {
        auto anchor = anchorAt(event->pos());
        if(anchor == m_mousePressAnchor) {
            emit linkActivated(m_mousePressAnchor);
        }
        m_mousePressAnchor.clear();
    }
    QTableView::mouseReleaseEvent(event);
}

QString LinkableTableView::anchorAt(const QPoint &pos) const {
    auto index = indexAt(pos);
    if(!index.isValid()) {
        return QString();
    }
    auto delegate = itemDelegate(index);
    auto linkableDelegate = qobject_cast<LinkableItemDelegate *>(delegate);
    if(linkableDelegate == nullptr) {
        return QString();
    }
    auto itemRect = visualRect(index);
    auto relativeClickPosition = pos - itemRect.topLeft();
    auto html = model()->data(index, Qt::DisplayRole).toString();
    return linkableDelegate->anchorAt(html, relativeClickPosition);
}

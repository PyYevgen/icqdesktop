#pragma once

#include "../../types/message.h"
#include "../../types/typing.h"

namespace Ui
{
	class ContactListItem;
}

namespace Logic
{
	class RecentItemDelegate : public QItemDelegate
	{
	public:

		RecentItemDelegate(QObject* parent);

		void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
		void paint(QPainter *painter, const QStyleOptionViewItem &option, const Data::DlgState& dlgState, bool fromAlert = false, bool dragOverlay = false) const;
		QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
		QSize sizeHintForAlert() const;
		int itemSize() const;
		void blockState(bool value);
        
        void addTyping(const TypingFires& _typing);
        void removeTyping(const TypingFires& _typing);

        void setDragIndex(const QModelIndex& index);

	private:

        std::list<TypingFires> typings_;
        
		struct ItemKey
		{
			const bool IsSelected;

			const bool IsHovered;

			const int UnreadDigitsNumber;

			ItemKey(const bool isSelected, const bool isHovered, const int unreadDigitsNumber);

			bool operator < (const ItemKey &_key) const;
		};

		bool StateBlocked_;
        QModelIndex DragIndex_;
	};
}
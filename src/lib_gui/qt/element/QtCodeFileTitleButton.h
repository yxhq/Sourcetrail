#ifndef QT_CODE_FILE_TITLE_BUTTON_H
#define QT_CODE_FILE_TITLE_BUTTON_H

#include "utility/file/FilePath.h"
#include "utility/TimeStamp.h"

#include "qt/element/QtIconButton.h"

class QtCodeFileTitleButton
	: public QtSelfRefreshIconButton
{
	Q_OBJECT

public:
	QtCodeFileTitleButton(QWidget* parent = nullptr);
	virtual ~QtCodeFileTitleButton();

	const FilePath& getFilePath() const;
	void setFilePath(const FilePath& filePath);

	void setModificationTime(const TimeStamp modificationTime);
	void setProject(const std::wstring& name);

	bool isComplete() const;
	void setIsComplete(bool isComplete);

	bool isIndexed() const;
	void setIsIndexed(bool isIndexed);

	void updateTexts();
	void updateFromOther(const QtCodeFileTitleButton* other);

protected:
	void contextMenuEvent(QContextMenuEvent* event);

	virtual void refresh();

private slots:
	void clickedTitle();

private:
	void updateIcon();
	void updateHatching();

	FilePath m_filePath;
	TimeStamp m_modificationTime;
	bool m_isComplete;
	bool m_isIndexed;
};

#endif // QT_CODE_FILE_TITLE_BUTTON_H

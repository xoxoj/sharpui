// 华勤科技版权所有 2010-2011
// 
// 文件名：Brush.h
// 功  能：定义刷子基类。
// 
// 作  者：汪荣
// 时  间：2010-07-02
// 
// ============================================================================

# ifndef _UIBRUSH_H_
# define _UIBRUSH_H_

#include <suicore/uiobject.h>
#include <suicore/drawing/uidrawing.h>

namespace suic
{

class SUICORE_API Brush : public RefObject
{
public:

    virtual ~Brush() {}

    virtual String GetKey();
    virtual bool Parse(const suic::String& xml) = 0;
    virtual bool Parse(void* node);
    virtual void Draw(DrawingContext* drawing, const Rect* lprc) = 0;
    virtual void Draw(DrawingContext* drawing, const Rect* lprc, const Rect* border);

protected:

    String _key;
};

typedef shared<Brush> BrushPtr;

class SUICORE_API Cursor : public RefObject
{
public:

    Cursor();
    ~Cursor();

    bool Load(const suic::String& source);
    suic::Handle GetHandle() const;

    void Clear();

protected:

    suic::Handle _handle;
};

typedef shared<Cursor> CursorPtr;

};

# endif

#ifndef _ERRORSTATE_H_
#define _ERRORSTATE_H_

namespace AMA
{
    class ErrorState
    {
        char* errMsg;

    public:
        explicit ErrorState(const char* errorMessage = nullptr);
        ErrorState(const ErrorState& em) = delete;
        ErrorState& operator= (const ErrorState& em) = delete;
        virtual ~ErrorState();
        
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message() const;


    };

    std::ostream& operator << (std::ostream&, const ErrorState&);

}

#endif // !_ERRORSTATE_H_

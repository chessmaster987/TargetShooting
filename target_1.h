#ifndef TARGET_H
#define TARGET_H

class Target{
public:
    Target();
    virtual ~Target();
    unsigned int Getm_Counter() { return m_Counter; }
    void Setm_Counter(unsigned int val) { m_Counter = val; }
    int GetShot() const { return m_Shot; }
    /** Set m_Shot
     * \param val New value to set
     */
private:
    unsigned int m_Counter;
};

#endif // TARGET_H

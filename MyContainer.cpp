//yoav1.nach@gmail.com

#include <ostream>



namespace Container
{

    //class of a container of comparable items
    template<typename T>
    class MyContainer
    {
        //header for the << operator
        friend std::ostream& operator<<(std::ostream& os,const MyContainer<T>& cont);
    private:
        // dynamic array to store the data
        T* data;
        // size of data array
        int dataSize;
        // the size of the items in data
        int realSize;

        //iterator for ascending order
        class AscendingIterator
        {
            private:
            //reference of the container
            const MyContainer<T>& container;
            //array that store the order of the container witout changing the container
            int* order;
            //the index of the current item of the container
            int index;
            //sort order in ascending order using bubble sort
            void sort(const MyContainer<T>& cont)
            {
                int size=cont.size();
                for(int i=0;i<size;i++)
                {
                    for(int j=0;j<size-i-1;j++)
                    {
                        int a = order[j];
                        int b = order[j+1];
                        if(cont.data[a]>cont.data[b])
                        {
                            int temp = order[j];
                            order[j]=order[j+1];
                            order[j+1]=temp;
                        }
                    }
                }
            }
            public:
                 // constructor for the iterator, create order and sorting 
                 //cont- referance to the container, end- true if creating end iterator
                AscendingIterator(const MyContainer<T>& cont,bool end):container(cont)
                {
                    order=new int[cont.size()];
                    for(int i=0;i<cont.size();i++)
                    {
                        order[i]=i;
                    }
                    sort(cont);
                    index=0;
                    if(end)
                    {
                        index=cont.size();
                    }
                }
                // return the current item
                const T& operator*() const
                {
                return container.data[order[index]];
                }
                // iterate index to the next item
                AscendingIterator& operator++()
                {
                    ++index;
                    return *this;
                }

                // return true if index is not the same as other iterator
                bool operator!=(const AscendingIterator& other) const
                {
                    return index != other.index;
                }

                //deconstruct the iterator
                ~AscendingIterator()
                {
                    delete[] order;
                }


        };
        //iterator for descending order
        class DescendingIterator
        {
            private:
            //reference of the container
            const MyContainer<T>& container;
            //array that store the order of the container witout changing the container
            int* order;
            //the index of the current item of the container
            int index;
            //sort order in descending order using bubble sort
            void sort(const MyContainer<T>& cont)
            {
                int size=cont.size();
                for(int i=0;i<size;i++)
                {
                    for(int j=0;j<size-i-1;j++)
                    {
                        int a = order[j];
                        int b = order[j+1];
                        if(cont.data[a]<cont.data[b])
                        {
                            int temp = order[j];
                            order[j]=order[j+1];
                            order[j+1]=temp;
                        }
                    }
                }
            }
            public:
                // constructor for the iterator, create order and sorting 
                //cont- referance to the container, end- true if creating end iterator
                DescendingIterator(const MyContainer<T>& cont,bool end):container(cont)
                {
                    order=new int[cont.size()];
                    for(int i=0;i<cont.size();i++)
                    {
                        order[i]=i;
                    }
                    sort(cont);
                    index=0;
                    if(end)
                    {
                        index=cont.size();
                    }
                }

                // return the current item
                const T& operator*() const
                {
                return container.data[order[index]];
                }
                // iterate index to the next item
                DescendingIterator& operator++()
                {
                    ++index;
                    return *this;
                }

                // return true if index is not the same as other iterator
                bool operator!=(const DescendingIterator& other) const
                {
                    return index != other.index;
                }

                //deconstruct the iterator
                ~DescendingIterator()
                {
                    delete[] order;
                }


        };
        //iterator for side cross order
        class SideCrossOrderIterator
        {
            private:
            //reference of the container
            const MyContainer<T>& container;
            //array that store the order of the container witout changing the container
            int* order;
            //the index of the current item of the container
            int index;
            //sort order in cross order by searching for the min/max and put it in place
            void sort(const MyContainer<T>& cont)
            {
                int size=cont.size();
                bool isMin=true;
                for(int i=0;i<size;i++)
                {
                    int minMax=i;
                    //for every index i of order search for min/max of all the items after i and put it in i
                    for(int j=i+1;j<size;j++)
                    {
                        int current=j;
                        if(isMin)
                        {
                            if(cont.data[order[minMax]]>cont.data[order[current]])
                            {
                                minMax=current;
                            }
                        }
                        else
                        {
                            if(cont.data[order[minMax]]<cont.data[order[current]])
                            {
                                minMax=current;
                            }
                        }
                    }
                    int temp=order[i];
                    order[i]=order[minMax];
                    order[minMax]=temp;
                    isMin=!isMin;
                }
            }
            public:
                // constructor for the iterator, create order and sorting 
                //cont- referance to the container, end- true if creating end iterator
                SideCrossOrderIterator(const MyContainer<T>& cont,bool end):container(cont)
                {
                    order=new int[cont.size()];
                    for(int i=0;i<cont.size();i++)
                    {
                        order[i]=i;
                    }
                    sort(cont);
                    index=0;
                    if(end)
                    {
                        index=cont.size();
                    }
                }

                // return the current item
                const T& operator*() const
                {
                return container.data[order[index]];
                }
                // iterate index to the next item
                SideCrossOrderIterator& operator++()
                {
                    ++index;
                    return *this;
                }

                // return true if index is not the same as other iterator
                bool operator!=(const SideCrossOrderIterator& other) const
                {
                    return index != other.index;
                }

                //deconstruct the iterator
                ~SideCrossOrderIterator()
                {
                    delete[] order;
                }


        };
        //iterator for reverse order
        class ReverseOrderiterator
        {
            private:
            //reference of the container
            const MyContainer<T>& container;
            //the index of the current item of the container
            int index;
            
            public:
                // constructor for the iterator, set index to the last item 
                //cont- referance to the container, end- true if creating end iterator
                ReverseOrderiterator(const MyContainer<T>& cont,bool end):container(cont)
                {
                    
                    index=cont.size()-1;
                    if(end)
                    {
                        index=-1;
                    }
                }

                // return the current item
                const T& operator*() const
                {
                return container.data[index];
                }

                // iterate index to the next item
                ReverseOrderiterator& operator++()
                {
                    --index;
                    return *this;
                }

                // return true if index is not the same as other iterator
                bool operator!=(const ReverseOrderiterator& other) const
                {
                    return index != other.index;
                }

                //deconstruct the iterator
                ~ReverseOrderiterator()
                {
                }


        };

        //iterator order side cross order
        class OrderIterator
        {
            private:
            //reference of the container
            const MyContainer<T>& container;
            //the index of the current item of the container
            int index;
            
            public:
                // constructor for the iterator, set index to the first item 
                //cont- referance to the container, end- true if creating end iterator
                OrderIterator(const MyContainer<T>& cont,bool end):container(cont)
                {
                    index=0;
                    if(end)
                    {
                        index=cont.size();
                    }
                }

                // return the current item
                const T& operator*() const
                {
                return container.data[index];
                }

                // iterate index to the next item
                OrderIterator& operator++()
                {
                    ++index;
                    return *this;
                }

                // return true if index is not the same as other iterator
                bool operator!=(const OrderIterator& other) const
                {
                    return index != other.index;
                }

                //deconstruct the iterator
                ~OrderIterator()
                {
                    //sdelete[] order;
                }


        };

        //iterator for middle out order
        class MiddleOutOrderIterator
        {
            private:
            //reference of the container
            const MyContainer<T>& container;
            //the index of the current item of the container
            int index;
            //indicate if to go left or right
            bool left=false;

            public:
                // constructor for the iterator, set index to the first item 
                //cont- referance to the container, end- true if creating end iterator
                MiddleOutOrderIterator(const MyContainer<T>& cont,bool end):container(cont)
                {
                    index=0;
                    if(end)
                    {
                        index=cont.size();
                    }
                }

                // return the current item
                const T& operator*() const
                {
                    //return the middle item first
                    if(index==0)
                    {
                        return container.data[container.size()/2];
                    }
                    //if turning left return the item with index/2 steps to the left
                    if(left)
                    {
                        return container.data[(container.size()-index-1)/2];
                    }
                    //if turning right return the item with index/2 steps to the right
                    return container.data[(container.size()+index)/2];
                }

                // iterate index to the next item and changing between left and right
                MiddleOutOrderIterator& operator++()
                {
                    ++index;
                    left=!left;
                    return *this;
                }

                // return true if index is not the same as other iterator
                bool operator!=(const MiddleOutOrderIterator& other) const
                {
                    return index != other.index;
                }

                //deconstruct the iterator
                ~MiddleOutOrderIterator()
                {
                }


        };

        //double the size of data
        //used when data is full and need to add another item
        void expendData()
        {
            T* newData =new T[this->dataSize*2];
            this->dataSize*=2;
            for(int i=0;i<this->size();i++)
            {
                newData[i]=this->data[i];
            }
            delete[] this->data;
            this->data=newData;
        }

        //move every item from index+1 one place to the left
        //used when removing item from the container
        void shrinkData(int index)
        {
            for(int i=index;i<this->size()-1;i++)
            {
                this->data[i]=this->data[i+1];
            }
        }
        
    public:
        //constructor for the container creates empty dynamic array in size 10
        MyContainer()
        {
            this->dataSize=10;
            this->data=new T[this->dataSize];
            this->realSize=0;
        }

        //add new element to the container
        void addElement(T element)
        {
            //if full -> expend data
            if(this->size()==this->dataSize)
            {
                this->expendData();
            }
            //add the elemnt at the end
            this->data[this->size()]=element;
            this->realSize++;
        }

        //return the size of the container
        int size() const
        {
            return this->realSize;
        }

        // remove element from the container (if element found more than one times remove all)
        //if element do not exist throws exeption 
        void removeElement(T element)
        {
            //check if element exist
            bool isExist=false;
            int i=0;
            //search every item
            while (i < this->size())
            {
                //if element found remove it end shrink data
                if (this->data[i] == element)
                {
                    this->shrinkData(i);
                    this->realSize--;
                    isExist = true;
                }
                else
                {
                    i++; 
                }
            }
            //if no element found throw exeption
            if(!isExist)
            {
                throw "element not found";
            }

        }

        // begin ascending order iterator
        AscendingIterator begin_ascending_order() const
        {
            return AscendingIterator(*this,false);
        }

        // end ascending order iterator
        AscendingIterator end_ascending_order() const
        {
            return AscendingIterator(*this,true);
        }

        // begin descending order iterator
        DescendingIterator begin_descending_order() const
        {
            return DescendingIterator(*this,false);
        }

        // end descending order iterator
        DescendingIterator end_descending_order() const
        {
            return DescendingIterator(*this,true);
        }

        // begin side cross order iterator
        SideCrossOrderIterator begin_side_cross_order() const
        {
            return SideCrossOrderIterator(*this,false);
        }

        // end side cross order iterator
        SideCrossOrderIterator end_side_cross_order() const
        {
            return SideCrossOrderIterator(*this,true);
        }

        // begin reverse order iterator
        ReverseOrderiterator begin_reverse_order() const
        {
            return ReverseOrderiterator(*this,false);
        }

        // end reverse order iterator
        ReverseOrderiterator end_reverse_order() const
        {
            return ReverseOrderiterator(*this,true);
        }

        // begin order iterator
        OrderIterator begin_order() const
        {
            return OrderIterator(*this,false);
        }

        // end order iterator
        OrderIterator end_order() const
        {
            return OrderIterator(*this,true);
        }

        // begin middle out order iterator
        MiddleOutOrderIterator begin_middle_out_order() const
        {
            return MiddleOutOrderIterator(*this,false);
        }

        // end middle out order iterator
        MiddleOutOrderIterator end_middle_out_order() const
        {
            return MiddleOutOrderIterator(*this,true);
        }

        //oprerator << for the container, print the container in [ , ] format
    //template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& cont)
    {
        os << "[";
        for (int i = 0; i < cont.size(); i++)
        {
            os << cont.data[i];
            if (i < cont.size() - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }
        
        //deconstruct the container
        ~MyContainer()
        {
            delete[]this->data;
        }


    };
    
    

    
}




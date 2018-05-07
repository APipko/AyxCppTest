
class Data
{
    int *ptr_data;
    
public:
    Data(int size)
        : ptr_data(new int[size])
    {
        //populate with data from our external data source via pre-existing method "fill"
        fill(ptr_data, size);
    }
    
    ~Data()
    {
        delete ptr_data;
    }
    
    Data(const Data& right)
    {
        ptr_data = right.ptr_data;
    }
    
    std::function<int(void)> GetDataReader()
    {
        int *current_position = ptr_data;
        int *end_position = ptr_data + 64;
        auto reader = [&]()
        {
            if(current_position == end_position)
            {
                return -1;
            }
            
            return *current_position++;
        };
        
        return reader;
    }
};
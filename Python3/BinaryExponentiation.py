def Power(x, y) : 
    res = 1
    if (x == 0) : 
        return 0
  
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x)
  
        y = y >> 1
        x = (x * x)
         
    return res 

def PowerMod(x, y, p) : 
    res = 1
    x = x % p  
    if (x == 0) : 
        return 0
  
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
  
        y = y >> 1
        x = (x * x) % p 
         
    return res 
      

print("Power is ", Power(2, 10))
print("Power Mod is", PowerMod(2, 10, 1e9+7))

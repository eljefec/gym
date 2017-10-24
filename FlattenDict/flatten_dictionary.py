def flatten_dictionary(dictionary):
  output = dict()
  for k,v in dictionary.items():
    if (type(v) is dict):
      nested = flatten_dictionary(v)
      for nested_k,nested_v in nested.items():
        if k and nested_k:
          composite_k = k + '.' + nested_k
        elif k:
          composite_k = k
        elif nested_k:
          composite_k = nested_k
        else:
          composite_k = ''
        output[composite_k] = nested_v
    else:
      output[k] = v
  return output

if __name__ == '__main__':
  d = {"Key1" : "1",
       "Key2" : {
         "a" : "2",
         "b" : "3",
         "c" : {
           "d" : "3",
           "e" : "1"
         }
       }
      }
  print(flatten_dictionary(d))

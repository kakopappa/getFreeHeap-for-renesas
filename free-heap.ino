#ifdef __cplusplus
extern "C" {
#endif
void * _sbrk(int);
#ifdef __cplusplus
}
#endif

#define GET_FREE_HEAP() ({ \
    char __attribute__((unused)) __top; \
    (uint32_t)(&__top - reinterpret_cast<char*>(_sbrk(0))); \
})

void setup()
{
  Serial.begin(38400);
  for (int i=0; i < 20; i++) {if (Serial) break; else delay(100);}

  Serial.print("Free Heap = "); Serial.println(GET_FREE_HEAP());
  Serial.flush();
}
void loop() { 
  Serial.print("Free Heap = "); Serial.println(GET_FREE_HEAP());
   delay(1000);
}

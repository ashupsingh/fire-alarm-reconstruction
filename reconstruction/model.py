"""New reconstruction, 2026-10-23. Demo inputs are synthetic, not historical results."""
class GasIndicator:
    def __init__(self, high=1800, low=1400, warmup=60, persistence=2):
        self.high,self.low,self.warmup,self.persistence=high,low,warmup,persistence
        self.above=None;self.alarm=False
    def step(self, raw, now):
        if raw is None or not 0<=raw<=4095:return 'SENSOR_FAULT'
        if now<self.warmup:return 'WARMING_UP'
        if raw>=self.high:
            if self.above is None:self.above=now
            if now-self.above>=self.persistence:self.alarm=True
        elif raw<=self.low:self.above=None;self.alarm=False
        else:self.above=None
        return 'INDICATION' if self.alarm else 'BASELINE'
def demo():
    c=GasIndicator();assert c.step(2000,0)=='WARMING_UP'
    assert c.step(2000,61)=='BASELINE';assert c.step(2000,64)=='INDICATION'
    assert c.step(1000,65)=='BASELINE';assert c.step(None,66)=='SENSOR_FAULT'
    return {'synthetic_threshold_test':'passed','concentration_calibrated':False}

if __name__ == "__main__":
    import json
    print(json.dumps(demo(), indent=2))

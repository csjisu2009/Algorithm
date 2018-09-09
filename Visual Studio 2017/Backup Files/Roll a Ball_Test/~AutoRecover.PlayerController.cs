using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {

    public float speed;

    private Rigidbody rb;
    private int count;

    // Use this for initialization
    void Start () {
        rb = GetComponent<Rigidbody>();
        count = 0;
	}

    //Update()
    //> Called Every Frame
    //> Used for  regular updates such as:
    //      Moving Non-Physics objects
    //      Simple Timers
    //      Receiving Input
    //> Update interval times varv
    //
    //★ Update() is not called on a regular timeline!! If one frame takes longer to process than the next, then the time between Update() calls will be different.
    void Update () {    // Update() is called once per frame; this is where most of our game code will go
        //TODO: caculate intervals
        //Debug.Log("Update time: " + Time.deltaTime);
    }

    //FixedUpdate()
    //> Called Every Physics Step
    //> FixedUpdate() intervals are consistent
    //> Used for regular updates such as:
    //      Adjusting Physics(Rigidbody) objects
    //
    //★ FixedUpdate() is called on a regular timeline!! And will have same time between calls.
    void FixedUpdate(){ //FixedUpdate() is called before performing any physics calculations; this is where our physics code will go
        //TODO: caculate intervals
        //Debug.Log("FixedUpdate time: " + Time.deltaTime);

        //We will be moving our ball by applying forces to the rigidbody == physics
        float moveVertical = Input.GetAxis("Vertical");
        float moveHorizontal = Input.GetAxis("Horizontal");

        Vector3 movement = new Vector3(moveHorizontal, 0.0f, moveVertical);
        rb.AddForce(movement*speed);
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Pick Up"))
        {
            other.gameObject.SetActive(false);
            count = count + 1;
        }
    }
}
